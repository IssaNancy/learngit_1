//注意:代码模板中的代码将会被复制到任何新创建的文件中，编辑代码模板中的代码，让他帮你自动增加固定代码吧
#include <iostream> 
using namespace std;
class Car;
class Boat
{
private:
	float boat;
public:
	Boat(float _boat = 0){ boat = _boat; }
	Boat(Boat &b);
	float getB(){ return boat; }

	friend int  totalWeight(Boat b, Car c);
};

class Car
{
private:
	float car;
public:
	Car(float _car = 0){ car = _car; }
	Car(Car &c);
	float getC(){ return car; }

	friend int totalWeight(Boat b, Car c);
};

Boat::Boat(Boat & b)
{
   boat = b.boat;
}
Car::Car(Car & c)
{
	car = c.car;
}


int totalWeight(Boat b, Car c)
{
	float boat=b.boat ;
	float car=c.car ;

	return boat + car;
}


int main()
{
	
	float boat;
	float car;
	
	cout << "Input boat weight:";
	cin >> boat ;
    cout<<"Input car weight:";
    cin>>car;
	Boat theb(boat);
	Car thec(car);

	cout << "Total weight:"<< totalWeight(theb,thec) << endl;

	return 0;
}
