#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    string Data{
        R"({"name":"Roderick","class":"Barbarian","level":5,"health":100,"isOnline":true,"pet":null,"guild":{"name":"The Fellowship","members":36},"equipment":[{"name":"Fiery Sword","damage":5,"critChance":0.2},{"name":"Iron Helmet","armor":30,"durability":4}]})"};
    Poco::JSON::Parser parser;
    Poco::Dynamic::Var result = parser.parse(Data);
    Poco::JSON::Object::Ptr root = result.extract<Poco::JSON::Object::Ptr>();
    std::string name = root->getValue<std::string>("name");
    std::string class1 = root->getValue<std::string>("class");
    std::string level1 = root->getValue<std::string>("level");
    int level = root->getValue<int>("level");
    cout << "name: " << name << "\n";
    cout << "class: " << class1 << "\n";
    cout << "level: " << level << "\n";
    cout << "level: " << level1 << "\n";
    cout << "\n";
    Poco::JSON::Object::Ptr guild = root->getObject("guild");
    std::string guildName = guild->getValue<std::string>("name");
    int members = guild->getValue<int>("members");

    cout << "Guild:\n";
    cout << "  Name: " << guildName << "\n";
    cout << "  Members: " << members << "\n\n";
    Poco::JSON::Array::Ptr equipment = root->getArray("equipment");
    cout << "Equipment:\n";
    for (size_t i = 0; i < equipment->size(); ++i)
    {
        Poco::JSON::Object::Ptr item = equipment->getObject(i);
        cout << "  Item " << (i + 1) << ":\n";
        for (auto &key : *item)
        {
            cout << "    " << key.first << ": " << key.second.toString() << "\n";
        }
    }
    cout << "\n";
    Poco::JSON::Object::Ptr jsonObj = new Poco::JSON::Object();
    jsonObj->set("name", "archit");
    jsonObj->set("age", 19);
    stringstream ss;
    jsonObj->stringify(ss);
    string output = ss.str();
    cout << output << "\n";
    return 0;
}