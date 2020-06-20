//注意:代码模板中的代码将会被复制到任何新创建的文件中，编辑代码模板中的代码，让他帮你自动增加固定代码吧
#include <iostream> 
#include <string>
using namespace std;
class document
{
    protected:
    string name;
    public:
    document() {};
};
class book:public document
{
    private:
    int pagecount;
    public:
    book()
    {
        cout<<"Input Name and Page:";
        cin>>name>>pagecount;
        cout<<"Name:"<<name<<endl;
        cout<<"Page:"<<pagecount;
    }
};
int main(){
    document a;
    book b;
    return 0;
    
}
