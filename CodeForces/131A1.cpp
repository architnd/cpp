#include <bits/stdc++.h>
using namespace std;

string cap(string s) {
    for (char &c : s) {
        if ('a' <= c && c <= 'z')
            c = 'A' + (c - 'a');
        else if ('A' <= c && c <= 'Z')
            c = 'a' + (c - 'A');
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    int n = 0;

    if ('A' <= s[0] && s[0] <= 'Z') {
        for (int i = 0; i < s.size(); i++) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                n++;
            }
        }
        if (n == s.size()) {
            cout << cap(s) << '\n';
            return 0;
        }
    } else if ('a' <= s[0] && s[0] <= 'z') {
        for (int i = 1; i < s.size(); i++) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                n++;
            }
        }
        if (n == s.size() - 1) {
            cout << cap(s) << '\n';
            return 0;
        }
    }

    // Default case: print the original string
    cout << s << '\n';
    return 0;
}
