#include <iostream>
#include <string>
using namespace std;
#include <set>
int main()
{
    multiset<string> arr;
    string s;
    cin>>s;
    while(s!="#")
    {
        int times=0;
multiset<string>::iterator iter;        
for (iter = arr.begin(); iter != arr.end(); iter++)
        {
            if (*iter == s)
                times++;
        }

        cout<<"times:"<<times<<endl;
        arr.insert(s);
        cin>>s;
    }
}


