#include <iostream>
using namespace std;

class Point
{
public:
    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    Point operator++ (int);
    Point operator-- (int);
    Point& operator++ ();
    Point& operator-- ();
    void display();
private:
    int x;
    int y;
};
Point Point::operator++ (int)
{
    Point t = *this;
    ++*this;
    return t;
}
Point Point::operator-- (int)
{
    Point t = *this;
    --*this;
    return t;
}
Point& Point::operator++ ()
{
    x++;
    y++;
    return *this;
}
Point& Point::operator-- ()
{
    x--;
    y--;
    return *this;
}
void Point::display()
{
    cout << "(" << x<< "," << y << ")" << endl;
}


int main()
{
    Point a,b(5,5);
    a=b++;
    a.display();
    a=++b;
    a.display();
    a=--b;
    a.display();
    a=b--;
    a.display();
}


