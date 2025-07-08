#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    map<string, int> myMap = {{"bat", 10}, {"pat", 15}, {"mat", 17}};

    for (map<string, int>::iterator it = myMap.begin();it != myMap.end(); it++){
        cout << it->first << " " << it->second << "\n";
    }

    for (map<string, int>::iterator it = begin(myMap);it != end(myMap); it++){
        cout << it->first << " " << it->second << "\n";
    }

    for (map<string, int>::const_iterator it = myMap.begin();it != myMap.end(); it++){
        cout << it->first << " " << it->second << "\n";
    }

    for (const auto& it : myMap){
        cout << it.first << " " << it.second << "\n";
    }

    for (auto& [key, value] : myMap){
        cout << key << " " << value << "\n";
    }

    for_each (myMap.begin(), myMap.end(), [](auto& it){
        cout << it.first << " " << it.second << "\n";
    });

    for_each (myMap.begin(), myMap.end(), [](const std::pair<string, int>& it){
        cout << it.first << " " << it.second << "\n";
    });

    for_each (myMap.begin(), myMap.end(), [](const std::tuple<string, int>& it){
        cout << std::get<0>(it) << " " << std::get<1>(it) << "\n";
    });

    return 0;
}