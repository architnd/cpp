#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int h = 0;
    int i = 0, len = s.size();
    while (i < len) {
        if (s[i] == '<' && s[i+1] != '/'){
            cout << string(2*h, ' ') << s.substr(i, 3) << "\n";
            i = i + 3;
            h++;
        }
        else if (s[i] == '<' && s[i+1] == '/')
        {
            h--;
            cout << string(2*h, ' ') << s.substr(i, 4) << "\n";
            i = i + 4;
        }
    }
    return 0;
}
//