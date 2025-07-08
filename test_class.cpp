#include<iostream>
#include<memory>
#include<vector>
#include<list>
using namespace std;
#if 0
class myClass{
    private:
        string a;
    public:
        static string b;
        myClass(){
            cout << "I am in Constructor \n";
        }
        myClass(const string& a){
            this->a = a;
            cout << "I am in parameterised Constructor \n";
        }
        myClass(const myClass& other){
            this->a = other.a;
            cout << "I am in Copy Constructor \n";
        }
        #if 0
        myClass operator+(const myClass& other){
            cout << "Operator+ Overloading \n";
            return myClass(this->a + other.a);
        }
        #endif
        #if 0
        virtual ~myClass(){
            cout << "I am in Destructor \n";
        }
        void setVal(const string& a){
            this->a = a;
        }
        virtual string getVal() const{  //virtual function
            return a;
        }
        virtual string getVal2() const = 0; // pure virtual function
        #endif
        #if 1
        static myClass& create(){
            static myClass c;
            return c;
        }
        static myClass& create(const string& b){
            static myClass c(b);
            return c;
        }
        string getVal() const{
            return a;
        }
        #endif
};
#if 0
class derivedClass : public myClass{
    private:
    public:
        derivedClass(){
            cout << "I am in Derived Class Constructor \n";
        }
        ~derivedClass() override{
            cout << "I am in Derived Class Destructor \n";
        }
        string getVal() const override{
            return myClass::getVal() + "abc";
        }
        string getVal2() const override{
            return "archit";   
        }
};
#endif
string myClass::b{"Hello World! \n"};
int main(){
    #if 0
    cout << myClass::b;
    shared_ptr<myClass> c = make_shared<myClass> ();
    string b = "hi";
    c->setVal(b);
    cout << c->getVal();
    #endif
    #if 1
    myClass& c = myClass::create();
    myClass& d = myClass::create("hi");
    myClass& e = myClass::create("hello");
    cout << e.getVal();
    #endif
    #if 0
    vector<myClass> vec;
    // vec.push_back(myClass("abc"));
    vec.emplace_back("abc");
    vec.emplace_back("xyz");
    vec.emplace_back(vec[0]+vec[1]);
    //vec.push_back(myClass("xyz"));
    #endif
    #if 0
    {
        //shared_ptr<myClass>  d = make_shared<derivedClass> ();
        myClass *d = new derivedClass;
        d->setVal("xyz");
        cout << d->getVal() << "\n";
        cout << d->getVal2() << "\n";
        delete d;
    }
    cout << "End Reached\n";
    #endif
    return 0;
}
#endif
#if 0
class myclass{
private:
    string a;
public:
    //myclass(){
        //cout << "This is constructor \n";
    //}
    myclass() = delete;
    myclass(const string& a){
        this->a = a;
        cout << "This is Parameterised constructor \n";
    }
    ~myclass(){
        cout << "This is destructor \n";
    }
    // static myclass& create(const string& b){
    //     static myclass c(b);
    //     return c;
    // }
    // string getVal() const{
    //     return a;
    // }
};
int main(){
    #if 0
    myclass& c = myclass::create(string("hi"));
    myclass& d = myclass::create(string("hello"));
    cout << d.getVal() << "\n";
    #endif
    myclass e;
    e.setVal("Received from Server")
    return 0;
}
#endif
#if 1

class myclass{
private:    
    myclass(){
        cout << "I am in Constructor\n";
    }
    ~myclass(){
        cout << "I am in Destructor\n";
    }
    myclass(const myclass& other) = delete;
    myclass& operator=(const myclass& other) = delete;
    //{return *this;}
public:
    static myclass& create(){ //factory function
        static myclass c;
        return c;
    }
};

int main(){
    myclass& a = myclass::create();
    // myclass b = a; // not allowed because copy constructor is deleted
    // a = b; // not allowed because assignment operatotor is deleted
    return 0;
}
#endif