#include<iostream>
using namespace std;
class myClass{
        private:
        public:
            myClass(){}
            ~myClass(){}
    };
void mySwap(int *a,int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int main(){
    int x = 10, y = 20;
    cout << x << y << endl;
    mySwap(&x,&y);
    cout << x << y << endl;
    myClass c1;
    return 0;
}