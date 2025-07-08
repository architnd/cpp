#include <iostream>
#include <string>
#include <vector>
// #include<type_traits>
using namespace std;
#if 0
void test(int& x){
    cout << "function with l-value reference called \n";
}
void test(int&& x){
    cout << "function with r-value reference called \n";
}
template<typename T>
void myFunction(T&& x){
    cout << x << "\n";
    cout << is_rvalue_reference_v<decltype(x)> << "\n";
    test(forward<T>(x));
}
int main(){
    int i = 20;
    myFunction(i);
    myFunction(20);
    return 0;
}
#endif
#if 0
class myClass{};
class derivedClass : public myClass{};
template<typename S, typename T>
void myFunction(S x, T y){
    //cout << typeid(S).name() << "\n";
    //cout << typeid(T).name() << "\n";
    if (is_pointer_v<T>){
        cout << "pointer recieved\n";
    }
    if (is_integral_v<T>){
        cout << "integral recieved\n";
    }
    if (is_floating_point_v<T>){
        cout << "floating point recieved\n";
    }
    if (is_array_v<T>){
        cout << "array recieved\n";
    }
    if (is_class_v<T>){
        cout << "class object recieved\n";
    }
    if (is_lvalue_reference_v<T>){
        cout << "l-value reference recieved\n";
    }
    if (is_rvalue_reference_v<T>){
        cout << "r-value reference recieved\n";
    }
    if (is_reference_v<T>){
        cout << "reference recieved\n";
    }
    if (is_base_of_v<S, T>){
        cout << "S is base of T\n";
    }
    if (is_const_v<T>){
        cout << "const recieved\n";
    }
}
int main(){
    int arr[3];
    myClass c;
    derivedClass d;
    const int a = 10;
    myFunction(10, "abc");
    myFunction(10, 20);
    myFunction(10, 20.3);
    myFunction(10, arr);
    myFunction(10, c);
    myFunction(10, move(c));
    myFunction(c, d);
    myFunction(10, a);
    return 0;
}
#endif
#if 1
template <typename T, int N = 10>
class myClass
{
private:
    T a;
    // T arr[N];
    vector<T> vec;

public:
    static T b;
    myClass(T a)
    {
        this->a = a;
        for (int i = 0; i < N; i++)
        {
            // arr[i] = i;
        }
    }
    myClass(initializer_list<T> arg)
    {
        for (auto &c : arg)
        {
            vec.push_back(c);
        }
    }
    ~myClass() {}
    T getVal() const
    {
        return a;
    }
};
template <typename T, int N>
T myClass<T, N>::b = 100;
template <>
char myClass<char>::b = 'a';

int main()
{
    cout << myClass<int>::b << "\n";
    cout << myClass<char>::b << "\n";
    cout << myClass<float>::b << "\n";
    myClass<int, 20> c(10);
    myClass<int> d({10, 20, 30, 40});
    myClass<char> e({'a', 'b', 'c', 'd'});
    cout << c.getVal() << "\n";
    return 0;
}
#endif
