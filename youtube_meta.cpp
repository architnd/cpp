// AIzaSyANPEOQ0A5x0MBkkOJBMFkamgQdUB5HovU
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
    std::string videoId = "GA_Uc4f54zo";
    std::string playListId = "PLy3XYRqs9KxMNugXMBVEfcHbuTjZqbv33";

    try
    {
        // Build the YouTube API URL
        //std::string path = "/youtube/v3/videos?part=snippet,statistics&id=" + videoId + "&key=" + apiKey;
        std::string path = "/youtube/v3/playlistItems?part=snippet&playlistId=" + playListId + "&key=" + apiKey;
        Poco::URI uri("https://www.googleapis.com" + path);

        // Create HTTPS session
        Poco::Net::HTTPSClientSession session(uri.getHost());
        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, uri.getPathAndQuery(), Poco::Net::HTTPMessage::HTTP_1_1);

        std::cout << request.getMethod() << " " << request.getURI() << " "
                  << request.getVersion() << "\r\n";

        for (const auto &header : request)
        {
            std::cout << header.first << ": " << header.second << "\r\n";
        }

        session.sendRequest(request);

        // Get the response stream
        Poco::Net::HTTPResponse response;
        std::istream &rs = session.receiveResponse(response);
        std::stringstream ss;
        Poco::StreamCopier::copyStream(rs, ss);
        std::cout << ss.str() << "\n\n";

        // Parse the JSON result
        Poco::JSON::Parser parser;
        Poco::Dynamic::Var result = parser.parse(ss.str());
        Poco::JSON::Object::Ptr root = result.extract<Poco::JSON::Object::Ptr>();
        Poco::JSON::Array::Ptr items = root->getArray("items");

        if (!items->empty())
        {
            Poco::JSON::Object::Ptr snippet = items->getObject(0)->getObject("snippet");
            Poco::JSON::Object::Ptr stats = items->getObject(0)->getObject("statistics");

            std::string title = snippet->getValue<std::string>("title");
            std::string description = snippet->getValue<std::string>("description");
            std::string views = stats->getValue<std::string>("viewCount");

            std::cout << "Title: " << title << std::endl;
            std::cout << "Description: " << description << std::endl;
            std::cout << "Views: " << views << std::endl;
        }
        else
        {
            std::cout << "Video not found." << std::endl;
        }
    }
    catch (const Poco::Exception &ex)
    {
        std::cerr << "Exception: " << ex.displayText() << std::endl;
    }

    return 0;
}
