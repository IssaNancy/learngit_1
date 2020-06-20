#include <iostream>
using namespace std;
class Dog
{
private:
   int age;
   int weight;
public:
    Dog()
    {
        age=0;
        weight=0;
    };
    void get();
  void print();

};
void Dog::get()
{
    cout<<"Input Age and Weight:";
    cin>>age>>weight;
}

void Dog::print()
{
    cout<<"Dog Age:"<<age<<" years"<<endl;
    cout<<"Dog Weight:"<<weight<<"kg"<<endl;
}
int main()
{
   Dog s;
   s.get();
   s.print();
   return 0;
}

