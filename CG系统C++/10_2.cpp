#include <iostream>

using namespace std;
#define PI 3.14;
class Shape
{
public:
    virtual void input() = 0;
    virtual double getArea() = 0;
    virtual double getPerim()= 0;
protected:
    double r;
    double l, w;
};
class Circle :public Shape
{
public:
    Circle(){}
    void input()
    {
        cout << "input r:";
        cin >> r;
    }
   double getArea()
    {
        return r * r * PI;
    }
   double getPerim() {
       return 2 * 3.14 * r;
    }
};
class Rectangle :public Shape
{
public:
    void input()
    {
        cout << "input l and w:";
        cin >> l >> w;
    }
    Rectangle(){}
    double getArea()
    {
        return l * w;
    }
    double getPerim()
    {
        return 2 *( l +w);
    }
};


int main()
{
    Circle a;
    Rectangle b;
    Shape *ptr[2]={&a,&b};
    int i;
    for(i=0;i<2;i++)
        ptr[i]->input();
    for(i=0;i<2;i++)
        cout<<"Area:"<<ptr[i]->getArea()<<" Perim:"<<ptr[i]->getPerim()<<endl;
    return 0;
}

