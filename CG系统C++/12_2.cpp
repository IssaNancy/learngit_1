#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> a;
    int n,m,x=0;
    cout<<"Input n and m:";
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    int start=0;
        while (a.size() != 1)
        {
            start = (start + m - 1) % a.size();
            a.erase(a.begin() + start);
        }

    cout<<"Result:"<<a[0]<<endl;
    return 0;
}


