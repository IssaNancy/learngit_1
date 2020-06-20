#include <iostream>
using namespace std;

class Mammal
{
public:
Mammal(){}
void virtual speak(){}
};
class Dog:public Mammal
{
public:
Dog(){}
void virtual speak()
{
cout<<"Dog is speaking!"<<endl;;
}
};


int main()
{
    Dog dog;
    Mammal *p;
    dog.speak();
    p=&dog;
    p->speak();
}


