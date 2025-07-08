#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;
int main(){
    string str1 = "the I am the archit the deshpande the";
    printf("%s\n", str1.c_str());
    for (const auto& s : str1){
        cout << s << " ";
    }
    cout << "\n";
    for (auto it = str1.begin(); it != str1.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";


    {
        size_t start = 0;
        size_t pos = str1.find(" ");
        while (pos != string::npos){
            string token = str1.substr(start, pos - start);
            cout << token << "\n";
            start = pos + 1;
            pos = str1.find(" ", start);
        }
        // if (str1.substr(start) != "\0"){
        //     cout << str1.substr(start) << "\n";
        // }
        if (!str1.substr(start).empty()){
            cout << str1.substr(start) << "\n";
        }
    }


    {
        string findstr{"the"};
        string replacestr{"abcdthe"};
        size_t pos = str1.find(findstr);
    
        while (pos != string::npos){
            str1.replace(pos, findstr.size(), replacestr);
            pos = str1.find(findstr, pos + 1 + replacestr.size());
        }
        cout << str1 << "\n";
    }


    string str2 = "https://192.168.1.2:8080";
    size_t pos1 = str2.find("//");
    if (pos1 != string::npos){
        size_t pos2 = str2.find(":", pos1 + 2);
        cout << str2.substr(pos1 + 2, pos2 - pos1 - 2) << "\n";
        int port = stoi(str2.substr(pos2 + 1));
        cout << port << "\n";
    }
    // string str3 = str2;
    // reverse(str3.begin(),str3.end());
    // cout << str3 << "\n";
    string str3 = string(str2.rbegin(),str2.rend());
    cout << str3 << "\n";


    string str4 = "the,I,am,the, archit,the, deshpande,the";
    str4.erase(remove(str4.begin(), str4.end(), ' '), str4.end());
    str4.erase(str4.begin(), str4.begin()+3);
    cout << str4 << "\n";

    ifstream inf("/proc/cpuinfo");
    if(!inf){
        cerr << "Cannot open file for reading\n";
    }
    else{
        cout << "File opened successfully\n";
    }
    string strInput{};
    while(getline(inf, strInput)){
        if (strInput.find("model name") != string::npos){
            //cout << strInput << "\n";
            size_t p = strInput.find(":");
            if (p != string::npos){
                cout << strInput.substr(strInput.find_first_not_of(' ', p + 1)) << "\n";
            }
            break;
        }
    }
    return 0;
}