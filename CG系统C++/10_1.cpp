#include <iostream>

#include <new>

#include <assert.h>

using namespace std;

class Abstract//������:���ܶ������

{

public:

    Abstract()

    {

        cout << "in Abstract()" << endl;

    }

    virtual void f() = 0;//���麯��

};

class Subclass :public Abstract
{
public:
    Subclass()
    {
        cout << "in Subclass()" << endl;
    }
    virtual void f()
    {
        cout << "Subclass::f()";
    }
};
int main()

{

    Abstract *p=new Subclass;
    p->f();
    delete p;
    return 0;

}


