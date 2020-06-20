
/*const float PI=3.14;
float mianji(int r)
{
    return r*r*PI;
}
float zhouchang(int r)
{
    return 2*PI*r;
}
int main()
{
    int r;
    cout<<"input r:";
    cin>>r;
    cout<<"the yuanmianji is"<<mianji(r)<<endl;
    cout<<"the yuanzhouchang is"<<zhouchang(r)<<endl;
    return 0;
}*/
/*
int main()
{
    cout<<"Hello!"<<endl;
    cout<<"Welcome to C++"<<endl;
    return 0;

}

class circle//Àà
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
class TAdd
{
    public:

 TAdd(int a,int b)

 {

    x=a;y=b;

    cout<<"constructor."<<endl;

    cout<<x<<","<<y<<endl;

 }

 ~TAdd()

 {

    cout<<"destructor."<<endl;

    cout<<x<<","<<y<<endl;

  }

  int add(){return x+y;}

private:

  int x,y;

};

int main()

{

   TAdd p1(3,4);

   cout<<"x+y="<<p1.add()<<endl;

   TAdd p2(30,40);

   cout<<"x+y="<<p2.add()<<endl;

   return 0;

}


class Date
{
public:
  Date()
  {
    cout<<"Input Date:";
    cin>>y>>m>>d;
  }
  int beLeapYear()
  {
    return ((y%4==0&&y%100!=0)||(y%400==0));
  }
  void addOneDay()
  {
       d++;
              if(beLeapYear())
              {
                  if(m==2 && d==30)
                  {
                      d=1;
                      m++;
                  }
              }
              else
              {
                  if(m==2 && d==29)
                  {
                      d=1;
                      m++;
                  }
              }
              if(d>31)
              {
                  if(m==12)
                  {
                      d=1;
                      m=1;
                      y++;
                  }
                  else
                      {
                  d=1;
                  m++;
                  }
              }
              else if(d==31)
              {
                  if(m==4 ||m==6 ||m==9 ||m==11)
                  {
                      d=1;
                      m++;
                  }
              }

  }
  void showDate()
  {
    cout<<y<<"-"<<m<<"-"<<d<<endl;
   }
private:
  int y,m,d;
  };
int main()
{
   Date d;
   d.showDate();
   d.addOneDay();
   d.showDate();
}
#include <iostream>
using namespace std;
class clock
{
public:
    void settime(int newH,int newM,int newS);
    void show()
    {
        cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
    private:
        int hour,minute,second;

};
void clock::settime(int newH,int newM,int newS)
{
    hour=newH;
    minute=newM;
    second=newS;
}
int main()
{
    clock a;
    cout<<"time is:";
    a.settime(5,3,5);
    a.show();
    return 0;
}
#include <iostream>
using namespace std;
class rectangle
{
    private:
    float a,b,c,d,area;
    public:
        void get()
        {
            cout<<"Input Point A:";
      cin>>a >>b;
            cout<<"Input Point B:";
            cin>>c >>d;
        }
        float mj(float a,float b,float c,float d)
        {
            area=(d-b)*(c-a);
            return area;
        }
        void show()
        {
            cout<<"Rectangle Area:"<<mj(a,b,c,d);
        }
};
int main()
{
    rectangle mr;
    mr.get();
          mr.show();

return 0;
}
*/
#include <iostream>
using namespace std;
class complex
{
private:
    float a,b;
public:
    complex(float a1,float b1);//构造函数
    complex(float a1);
    void add(complex &c);
    void show();
};
complex::complex(float a1,float b1)
{
    a=a1;
    b=b1;
}
complex::complex(float a1)
{
    a=a1;
    b=0;
}
void complex::add(complex &c)
{
    a+=c.a;
    b+=c.b;
}
void complex::show()
{
   cout<<a<<"+"<<b<<"i"<<endl;
}
int main()
{

    complex c1(3,5);
    complex c2=4.5;
    c1.add(c2);
    c1.show();
return 0;

}

