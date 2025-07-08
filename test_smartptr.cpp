#include<iostream>
#include<memory>
using namespace std;

class myClass{
    public:
        myClass(){
            cout << "I am in Constructor \n";
        }
        ~myClass(){
            cout << "I am in Destructor \n";
        }
};

int main(){

#if 0
    int p = 10;
    int *q = &p;
    cout << *q << "\n";
    //int x[15];

    int *x = new int(15);
    //cout << sizeof(int) << " " << sizeof(char) << " " << sizeof(short) << " " << sizeof(float) << " " << sizeof(double) << " " << sizeof(int*) << "\n";
    int *t = x;
    for (int i = 0; i < 15; i++){
        //x[i] = i;
        *t = i + 1;
        t++;
    }
    for (int i = 0; i < 15; i++){
        cout << x[i] << " ";
    }
#endif
    //int *p = new int(1);
    //*p = 10;
    //cout << *p;
    shared_ptr<int> p = make_shared<int> (10);
    shared_ptr<int> q = p;
    cout << p.use_count() << "\n";
    q.reset();
    cout << p.use_count() << "\n";
    p.reset();
    cout << p.use_count() << "\n";
    unique_ptr<int> r = make_unique<int> (12);
    cout << *r << "\n";
    unique_ptr<int> s = move(r);
    //cout << *r << "\n";
    cout << *s << "\n";
    //cout << *p;
    {
        //myClass *c = new myClass;
        //delete c;
        shared_ptr<myClass> d = make_shared<myClass> ();
        unique_ptr<myClass> e = make_unique<myClass> ();
    }
    cout << "scope ended \n";
    return 0;
}