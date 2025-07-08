#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/URI.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>
#include <iostream>
#include <sstream>

int main()
{
    std::string apiKey = "AIzaSyANPEOQ0A5x0MBkkOJBMFkamgQdUB5HovU";
    std::string playListId = "PLy3XYRqs9KxMNugXMBVEfcHbuTjZqbv33";

    try
    {
        // Build the API URL
        std::string path = "/youtube/v3/playlistItems?part=snippet&playlistId=" + playListId + "&maxResults=10&key=" + apiKey;
        Poco::URI uri("https://www.googleapis.com" + path);

        // Create HTTPS session
        Poco::Net::HTTPSClientSession session(uri.getHost());
        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, uri.getPathAndQuery(), Poco::Net::HTTPMessage::HTTP_1_1);

        session.sendRequest(request);

        // Get the response stream
        Poco::Net::HTTPResponse response;
        std::istream &rs = session.receiveResponse(response);
        std::stringstream ss;
        Poco::StreamCopier::copyStream(rs, ss);

        std::cout << ss.str();

        // Parse the JSON result
        Poco::JSON::Parser parser;
        Poco::Dynamic::Var result = parser.parse(ss.str());
        Poco::JSON::Object::Ptr root = result.extract<Poco::JSON::Object::Ptr>();
        Poco::JSON::Array::Ptr items = root->getArray("items");

        for (size_t i = 0; i < items->size(); ++i)
        {
            Poco::JSON::Object::Ptr item = items->getObject(i);
            Poco::JSON::Object::Ptr snippet = item->getObject("snippet");

            std::string title = snippet->getValue<std::string>("title");
            std::string description = snippet->getValue<std::string>("description");

            std::cout << "\nVideo " << (i + 1) << ":\n";
            std::cout << "Title: " << title << "\n";
            std::cout << "Description: " << description << "\n";
        }
    }
    catch (const Poco::Exception &ex)
    {
        std::cerr << "Exception: " << ex.displayText() << std::endl;
    }

    return 0;
}
