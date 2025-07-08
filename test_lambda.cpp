#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int x = 100;
    auto myFunction = [&x]() {
        x = x + 10;
        cout << "hi \n" << x << "\n";
    };
    myFunction();
    myFunction();
    cout << x << "\n";
    vector<int> vec = {20, 40, 30, 10, 11, 52};
    for (const auto& i : vec){
        cout << i << " ";
    }
    cout << "\n";
    for_each(vec.begin(),vec.end(), [](auto& arg){
            arg = arg * 10;
    });
    for (const auto& i : vec){
        cout << i << " ";
    }
    cout << "\n";
    sort(vec.begin(), vec.end(), [](auto& arg1, auto& arg2){
        return (arg1 < arg2);
    });
    for (const auto& i : vec){
        cout << i << " ";
    }
    cout << "\n";
    auto found = find_if(vec.begin(), vec.end(), [](auto& arg1){
        return !(arg1 % 13);
    });
    if (found != vec.end()){
        cout << *found;
    }
    cout << "\n";
    return 0;
}