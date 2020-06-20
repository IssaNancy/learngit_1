#include <iostream>
using namespace std;
#define N 100
class CTime
{
public:
    CTime(){}
    friend int operator-(CTime, CTime);
    void input()
    {
        cin >> minute >> second ;
    }
    int beZero()
    {
        if (minute == 00 && second == 00)
            return 1;
        else return 0;
    }
private:
    int minute;
    int second;
};
int operator-(CTime t2, CTime t1)
{
    return (t2.minute - t1.minute) * 60 + t2.second - t1.second;
}

int  main()
{
    CTime time[N];
    int count=-1;
    do
    {
        count++;
        time[2*count].input();
        time[2*count+1].input();
    }while(!(time[2*count].beZero()&&time[2*count+1].beZero()));
    for(int i=0;i<count;i++)
    {
        cout<<time[2*i+1]-time[2*i]<<endl;
    }
    return  0;
}


