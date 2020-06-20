#include <iostream>
#include <fstream>
using namespace std;

class dog {
public:
	dog(int weight, int age) :m_Weight(weight), m_Age(age) {};
	~dog() {};
	int getW() { return m_Weight; }
	int getAge() { return m_Age; }
private:
	int m_Weight,m_Age;
};

int main()
{
	ofstream out("./dog.txt", ios_base::out|ios::binary);
	dog d1(5, 10);
	out << d1.getW() << endl << d1.getAge() << endl;
	out.close();

	ifstream in("./dog.txt", ios_base::in|ios::binary);
	int w, a;
	in >> w >> a;
	dog d2(w, a);
	in.close();
	cout << "Weight:" << d2.getW() << " Age:" << d2.getAge();
	return 0;
}
