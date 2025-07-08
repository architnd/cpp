#include <iostream>
using namespace std;
int main()
{
    string str1 = "the I am the archit the deshpande the";
    printf("%s\n", str1.c_str());
    for (const auto &s : str1)
    {
        cout << s << " ";
    }
    cout << "\n";
    for (auto it = str1.begin(); it != str1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
    {
        size_t start = 0;
        size_t pos = str1.find(" ");
        while(pos != string::npos){
            string token = str1.substr(start, pos - start);
            cout << token << "\n";
            start = pos + 1;
            pos = str1.find(" ", start);
        }
        #if 0
        if (str1.substr(start) != "\0"){
            cout << str1.substr(start);
        }
        #endif
        #if 1
        if (!str1.substr(start).empty()){
            cout << str1.substr(start);
        }
        #endif
    }
    {
        string findstr{"the"};
        string replacestr{"abcdef"};
        size_t pos = str1.find(findstr);
        while (pos != string::npos){
            str1.replace(pos, findstr.size(), replacestr);
            pos = str1.find(findstr, pos + replacestr.size() + 1);
        }
        cout << str1 << "\n";
    }
    cout << "\n";
    return 0;
}