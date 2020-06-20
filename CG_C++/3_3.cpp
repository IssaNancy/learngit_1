#include <iostream>
#include <cmath>
using namespace std;
class Point
{
public:
    Point()
    {
        cout<<"Input Point:";
        cin>>x>>y;
    }
    Point(const Point&p)
    {
        x=p.x;
        y=p.y;
        cout<<"Copy Point!"<<endl;
    }
    float getX(){return x;}
    float getY(){return y;}
    void setX(float a){x=a;}
    void setY(float b){y=b;}
private:
    float x,y;
};
class Triangle
{
public:
    Triangle(Point &xp1,Point &xp2,Point &xp3);
    float getArea();
private:
    Point p1,p2,p3;
};
Triangle::Triangle(Point  &xp1,Point  &xp2,Point  &xp3):
p1(xp1),p2(xp2),p3(xp3)
{}

float Triangle::getArea()
{
float s1,s2,s3;
s1=sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX())+(p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
s2= sqrt((p3.getX()-p2.getX())*(p3.getX()-p2.getX())+(p3.getY()-p2.getY())*(p3.getY()-p2.getY()));
s3= sqrt((p1.getX()-p3.getX())*(p1.getX()-p3.getX())+(p1.getY()-p3.getY())*(p1.getY()-p3.getY()));
float p,area;
p=(s1+s2+s3)/2.0;
area=sqrt(p*(p-s1)*(p-s2)*(p-s3));
return area;
}

int main()
{
    Point p1,p2,p3;
    Triangle t(p1,p2,p3);
    cout<<"Triangle Area:"<<t.getArea()<<endl;
    return 0;
}


