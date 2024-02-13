
//Hierarchical inheritance
#include <iostream>

using namespace std;
class A
{
    public:
    int a;
    A(int x):a(x)
    {
        cout<<"parameterized constructor A"<<endl;
    }
    ~A()
    {
        cout<<"Destructor A"<<endl;
    }
    int get(){
        return a;
    }
};
class B:public A
{
    public:
    int a,b;
    B(int x,int y,int i):A(x),a(y),b(i)
    {
        cout<<"parameterized constructor B"<<endl;
    }
      void print()
    {
        cout<<"class A data member value a:"<<get()<<endl;
        cout<<"a:"<<a<<endl;
        cout<<"b:"<<b<<endl;
    }
    ~B()
    {
        cout<<"Destructor B"<<endl;
    }
};
class C:public A
{
    public:
    int a,b,c;
    C(int l,int x,int y,int i):A(l),a(x),b(y),c(i)
    {
        cout<<"parameterized constructor C"<<endl;
    }
    void print()
    {
        cout<<"class A data member value a:"<<get()<<endl;
        cout<<"a:"<<a<<endl;
        cout<<"b:"<<b<<endl;
        cout<<"c:"<<c<<endl;
    }
    ~C()
    {
        cout<<"Destructor C"<<endl;
    }
};
class D:public A
{
    public:
    int a,b,c,d;
    D(int x,int y,int z,int i,int j ):A(x),a(y),b(z),c(i),d(j)
    {
        cout<<"parameterized constructor D"<<endl;
    }
    ~D()
    {
        cout<<"Destructor D"<<endl;
    }
    void print()
    {
        cout<<"class A data member :a="<<A::a<<endl;
        cout<<"a:"<<a<<endl;
        cout<<"b:"<<b<<endl;
        cout<<"c:"<<c<<endl;
    }
    
};
int main()
{
    B obj1(1,2,3);
    cout<<"A base and B derived class data member value:"<<endl;
    obj1.print();
    cout<<"A class value:"<<obj1.get()<<endl;
    cout<<"************************************************"<<endl;
    C obj2(1,2,3,4);
    cout<<"A base and C derived class data member value:"<<endl;
    obj2.print();
    cout<<"************************************************"<<endl;
    D obj3(1,2,3,4,5);
    cout<<"A base and D derived class Data member values:"<<endl;
    obj3.print();
    

    return 0;
}
