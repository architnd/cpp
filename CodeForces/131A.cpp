#include<bits/stdc++.h>
using namespace std;
string cap(string s){
    for (int i = 0; i < s.size(); i++){
        if ('a' <= s[i] && s[i] <= 'z'){
                s[i] = 'A' + (s[i] - 'a');
            }
        else if ('A' <= s[i] && s[i] <= 'Z'){
            s[i] = 'a' + (s[i] - 'A');
        }
    }
    return s;
}
int main(){
    string s;
    cin >> s;
    int n = 0,o = 0, i;
    if ('A' <= s[0] && s[0] <= 'Z'){
        for (i = 0; i < s.size(); i++){
            if ('A' <= s[i] && s[i] <= 'Z'){
                n++;
            }
        }
        if (n == s.size()){
            cout << cap(s) << "\n";
            o++;
        }
    }
    else if ('a' <= s[0] && s[0] <= 'z'){
        n = 0;
        for (i = 1; i < s.size(); i++){
            if ('A' <= s[i] && s[i] <= 'Z'){
                n++;
            }
        }
        if (n == s.size() - 1){
            cout << cap(s) << "\n";
            o++;
        }
    }
    if (o == 0){
        cout << s << "\n";
    }
    return 0;
}