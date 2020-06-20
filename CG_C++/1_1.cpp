#include <iostream>
using namespace std;
const float PI=3.14;
class circle
{
private:
   float radious;
   float area;
public:
    circle()
    {
        radious=0;
    };
    void get();
  float getArea();
  void print();

};
void circle::get()
{
    cout<<"Input Radius:";
    cin>>radious;
}

float circle::getArea()
{
    area=PI*radious*radious;
    return area;
}
void circle::print()
{
    cout<<"Area:"<<area<<endl;
}
int main()
{
   circle s;
   s.get();
   s.getArea();
   s.print();
   return 0;
}



