#include <iostream>
using namespace std;
class Exception
{
public:
    virtual void showMessage()=0;
};

class RangeError : public Exception
{
public:
    RangeError() {
    }
    void showMessage()
    {
        cout << "Exception:Range Error!" << endl;
    }
};

int main()
{
    try
    {
        int n;
        cout<<"Input n(1<=n<=100):";
        cin>>n;
        if(n<1||n>100)
            throw RangeError();

        cout<<"n:"<<n<<endl;
    }
    catch(Exception& e)
    {
        e.showMessage();
    }
}


