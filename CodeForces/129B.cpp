#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b,i;
    cin >> n >> m;
    vector<int> vec1;
    for (i = 0; i < m; i++){
         cin >> a >> b;
         vec1.push_back(a);
         vec1.push_back(b);
    }
    vector<int> vec2(n, 0);
    for (i = 0; i < 2*m; i++){
        vec2[vec1[i]-1]++;
    }
    for (i = 0; i < n; i++){
        if (vec1[i] == 1)
    }
    return 0;
}