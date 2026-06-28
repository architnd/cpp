#include<iostream>
#include<vector>
using namespace std;

int main(){
    int* arr{new int[10]};
    for (int i = 0; i < 10; i++){
        arr[i] = i;
    }
    try{
        int a,b;
        cin >> a >> b;
        if (b == 0){
            throw runtime_error{"Denominator is zero."};
        }else{
            cout << "\n" << a/b << "\n";
        }
    }
    catch (runtime_error& e){
        cerr << "Runtime Error : " << e.what() << "\n";
    }
    
    try{
        vector<int> vec = {1,2,3};
        int c = vec.at(10);
        cout << "hello";
    }
    catch (runtime_error& e){
        cerr << "Runtime Error : " << e.what() << "\n";
    }
    catch (out_of_range& e){
        cerr << "Out of Range : " << e.what() << "\n";
    }
    catch (logic_error e){
        cerr << "Logic Error : " << e.what() << "\n";
    }
    return 0;
}