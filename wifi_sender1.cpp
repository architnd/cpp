#include <iostream>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Array.h>
#include <Poco/JSON/Stringifier.h>

int main() {
    try {
        // Construct simple JSON payload
        Poco::JSON::Object::Ptr wifi = new Poco::JSON::Object();
        wifi->set("bssid", "test");
        wifi->set("frequency", "2412");
        wifi->set("signalLevel", "-50");
        wifi->set("ssid", "DemoNet");

        Poco::JSON::Array::Ptr arr = new Poco::JSON::Array();
        arr->add(wifi);

        Poco::JSON::Object::Ptr root = new Poco::JSON::Object();
        root->set("results", arr);

        std::stringstream jsonStream;
        Poco::JSON::Stringifier::stringify(root, jsonStream);
        std::string body = jsonStream.str();

        std::cout << "Sending JSON:\n" << body << "\n";

        Poco::Net::HTTPClientSession session("127.0.0.1", 8000);
        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, "/wifi", Poco::Net::HTTPMessage::HTTP_1_1);
        request.setContentType("application/json");
        request.setContentLength(body.length());

        std::ostream& os = session.sendRequest(request);
        os << body;

        Poco::Net::HTTPResponse response;
        std::istream& rs = session.receiveResponse(response);
        std::stringstream resStream;
        Poco::StreamCopier::copyStream(rs, resStream);

        std::cout << "Response (" << response.getStatus() << "): " << resStream.str() << std::endl;
    } catch (Poco::Exception& e) {
        std::cerr << "POCO Exception: " << e.displayText() << std::endl;
    }
}
