#include <iostream>
#include <string>
using namespace std;
class Object
{
public:
    Object()
    {
        cout<<"Constructing Object!"<<endl;
    }
    ~Object()
    {
        cout<<"Destructing Object!"<<endl;
    }
    void getInfo()
    {
        cout<<"Input weight:";
        cin>>weight;
    }
    void showInfo()
    {
        cout<<"Weight:"<<weight<<endl;
    }
private:
    int weight;
};

class Box:public Object
{
    private:
    int height,width,weight;
    public:
    Box() 
        { 
                cout<<"Constructing Box!"<<endl; 
        } 
        ~Box() 
        { 
                cout<<"Destructing Box!"<<endl; 
        } 
        void getInfo() 
        { 

     cout<<"Input weight:"; 
cin>>weight;
                cout<<"Input height and width:"; 
                cin>>height>>width;
        } 
        void showInfo() 
        { 
     cout<<"Weight:"<<weight<<endl;
                cout<<"Height and width:"<<height<<","<<width<<endl; 
        } 
};

int main()
{
    Box box;
    box.getInfo();
    box.showInfo();
    return 0;
}


