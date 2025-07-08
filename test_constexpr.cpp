#include<iostream>
using namespace std;

constexpr int sum(int x, int y){
    return x + y;
}

template<typename T>
constexpr auto sum2(T x, T y){
    //cout << typeid(T).name() << endl;
    if constexpr (is_pointer_v<T>){
        return *x + *y;
    }
    else{
        return x + y;
    }
}

class myClass{
    public:
        constexpr myClass(){
        }
        constexpr int getValue(){
            return 100;
        }    
};

int main(){
    constexpr int i = 10;
    constexpr int j = i + 20;
    static_assert(j == 30, "not correct");

    static_assert(sum(i, j) == 40, "incorrect");
    const int u = 15, v = 20;
    cout << sum(u, v) << endl;

    myClass c;
    static_assert(c.getValue() == 100, "incorrect");

    constexpr auto a = sum2(&u, &v);
    static_assert(a == 35, "incorrect");
    cout << a;
    
    // const int z = 10;
    // constexpr int y = z;

    //constexpr int x = y;
    return 0;
}