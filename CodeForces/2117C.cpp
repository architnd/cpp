#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, i;
    cin >> t;
    while(t-- > 0){
        int n;
        cin >> n;
        vector<int> vec(n);
        for (i = 0; i < n; i++){
            cin >> vec[i];
        }
        // vector<vector<int>> vec1;
        // vec1[0].push_back(vec[0]);
        // vec1[0].push_back(vec[1]);
        unordered_set<int> s;
        s.insert(vec[0]);
        s.insert(vec[1]);
        int part = 1;
        for (i = 2; i < n; i++){
              
        }
    }
    return 0;
}