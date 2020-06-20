#include <iostream>
#include <string>
using namespace std;

class CCard
{
private:
string id,pass;
static double money;
int flat;
public:
CCard(){};
CCard(string idname,string password)
{
cout<<"Input password:";
cin>>password;
if(password!="111111")
{
cout<<"Password error!";
flat=0;
}
}
void  deposit(double m)
{
money=money-m;
}
void draw(double m)
{
if(flat!=0)
money=money-m;
else cout<<endl;
}
static void showMoney()
{
 cout<<"Money:"<<money<<endl;
}
};


double CCard::money = 20000;

int main()
{
	CCard::showMoney();
	CCard card1("666666","111111");
	card1.draw(800);
	CCard::showMoney();
	CCard card2("888888","111111");
	card2.draw(900);
	CCard::showMoney();
	return 0;
}

