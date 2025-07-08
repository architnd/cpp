#include<iostream>
using namespace std;
class A{};
class B : public A{};
class C{};
int main(){
    {
        int a = 10;
        float b = static_cast<float> (a);
        a = static_cast<int> (b);
        //float *c = static_cast<float*> (&a); //Not Allowed
        void *x = static_cast<void*> (&a);
        float *c = static_cast<float*> (x);
    }
    {
        A *a = new A;
        B *b = static_cast<B*> (a);
        a = static_cast<A*> (b);
        //C *c = static_cast<C*> (a); // not allowed
    }
    {
        //A *a = new A;
        //B *b = dynamic_cast<B*> (a); //not allowed - base class object cannot be assigned to derived class pointer
        B *b = new B;
        A *a = dynamic_cast<A*> (b);
    }
    {
        A *a = new A;
        C *c = reinterpret_cast<C*> (a);
    }
    {
        auto myFunction = [](A& a){};
        const A a;
        myFunction(const_cast<A&> (a));
    }
    return 0;
}