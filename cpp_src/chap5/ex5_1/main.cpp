#include <iostream>
using namespace std;

class Circle{
private:
    int radius;
public:
    Circle();
    Circle(int radius);
    ~Circle();

    double getArea();
    int getRadius();
    void setRadius(int radius);
};

//--------------------------------------------------------------------------

Circle::Circle()
{
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int radius)
{
    this->radius = radius;
    cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle()
{
    cout << "소멸자 실행 radius = " << radius << endl;
}

double Circle::getArea()
{
    return 3.14*radius*radius;
}

int Circle::getRadius()
{
    return radius;
}

void Circle::setRadius(int radius)
{
    this->radius = radius;
}

void increase(Circle c)
{
    int r = c.getRadius();
    c.setRadius(r+1);
}

//-------------------------------------------------------------------------

int main(void)
{
    Circle waffle(30);

    increase(waffle);

    cout << waffle.getRadius() << endl;
    
    return 0;
}