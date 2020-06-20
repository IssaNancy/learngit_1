//注意:代码模板中的代码将会被复制到任何新创建的文件中，编辑代码模板中的代码，让他帮你自动增加固定代码吧
#include <iostream> 
using namespace std;
#define PI 3.14
class Shape
{
    public:
    Shape(){}
    ~Shape(){}
    virtual float getArea()=0;
};
class Rectangle:public Shape
{
    public:
    Rectangle(int a,int b):k(a),j(b){}
    protected:
    int k,j;
    float getArea()
    {
    return k*j;
    }
};
class Circle:public Shape
{
    public:
    Circle(int r):radious(r){}
    ~Circle(){}
    private:
    int radious;
        float getArea()
    {
        return PI*radious*radious;
    }
};
class Square:public Rectangle
{
    Square();
};
int main()
{
    int a,b,r;
    Shape *m;
    cout<<"Input a,b:";
    cin>>a>>b;
    cout<<"Input r:";
cin>>r;
    m=new Rectangle(a,b);
    cout<<"Rectangle Area:"<<m->getArea()<<",";
    delete m;
m=new Circle(r);
cout<<"Circle Area:"<<m->getArea();
delete m;
return 0;
}
