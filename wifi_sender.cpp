#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/JSON/Array.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Stringifier.h>
using namespace std;
int main() {
    vector<string> bssids;
    vector<string> frequencies;
    vector<string> signalLevels;
    vector<string> ssids;
    ifstream inf("scan_results.txt");
    if (!inf) {
        cerr << "Cannot open file for reading\n";
        return 1;
    }
    string strInput;
    getline(inf, strInput);
    while (getline(inf, strInput)) {
        size_t firstBracket = strInput.find('[');
        size_t lastBracket = strInput.rfind(']');
        if (firstBracket != string::npos && lastBracket != string::npos && lastBracket > firstBracket) {
            strInput.erase(firstBracket, lastBracket - firstBracket + 1);
        }
        istringstream iss(strInput);
        string bssid, freq, signal, rest;
        iss >> bssid >> freq >> signal;
        getline(iss, rest);
        rest.erase(0, rest.find_first_not_of("\t"));
        rest.erase(rest.find_last_not_of(" \t\n\r") + 1);
        bssids.push_back(bssid);
        frequencies.push_back(freq);
        signalLevels.push_back(signal);
        ssids.push_back(rest);
    }
    // for (size_t i = 0; i < bssids.size(); ++i) {
    //     cout << bssids[i] << "\t"
    //          << frequencies[i] << "\t"
    //          << signalLevels[i] << "\t"
    //          << ssids[i] << "\n";
    // }
    try {
        // Create array of scan results
        Poco::JSON::Array::Ptr wifiArray = new Poco::JSON::Array();
        for (size_t i = 0; i < bssids.size(); ++i) {
                Poco::JSON::Object::Ptr wifi = new Poco::JSON::Object();
                wifi->set("bssid", bssids[i]);
                wifi->set("frequency", frequencies[i]);
                wifi->set("signalLevel", signalLevels[i]);
                wifi->set("ssid", ssids[i]);
                wifiArray->add(wifi);
            }

            Poco::JSON::Object::Ptr root = new Poco::JSON::Object();
            root->set("results", wifiArray);

            std::stringstream jsonStream;
            Poco::JSON::Stringifier::stringify(root, jsonStream);
            std::string requestBody = jsonStream.str();

            // Send POST request
            Poco::Net::HTTPClientSession session("127.0.0.1", 8000);
            Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, "/wifi", Poco::Net::HTTPMessage::HTTP_1_1);
            request.setContentType("application/json");
            request.setContentLength(requestBody.length());

            std::ostream& os = session.sendRequest(request);
            os << requestBody;

            Poco::Net::HTTPResponse response;
            std::istream& rs = session.receiveResponse(response);
            std::stringstream responseStream;
            Poco::StreamCopier::copyStream(rs, responseStream);

            std::cout << "Response: " << responseStream.str() << std::endl;
        } catch (Poco::Exception& ex) {
            std::cerr << "POCO Exception: " << ex.displayText() << std::endl;
        }
    return 0;
}