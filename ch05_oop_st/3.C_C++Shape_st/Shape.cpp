#include <iostream>
using namespace std;

class Shape
{
public:
	virtual double GetArea() = 0;
	virtual void Draw() const = 0;

	Shape();

};

Shape::Shape()
{
}


// 사각형을 상징하는 클래스
class Rectangle : public Shape
{
public:
	virtual double GetArea();
	virtual void Draw() const;

	Rectangle();
	Rectangle(double width, double height);

protected:
	double m_width;
	double m_height;

};

Rectangle::Rectangle()
{
	m_width = m_height = 100.0f;
}

Rectangle::Rectangle(double width, double height)
: m_width(width), m_height(height)
{
}

void Rectangle::Draw() const
{
	cout << "[Rectangle]\n";
}

double Rectangle::GetArea()
{
	return m_width*m_height;
}

// 원을 상징하는 클래스
class Circle : public Shape
{
public:
	virtual double GetArea();
	virtual void Draw() const;

	Circle();
	Circle(double radius);

protected:
	double m_radius;
};

Circle::Circle()
{
	m_radius = 100.0f;
}

Circle::Circle(double radius)
: m_radius (radius)
{
}

void Circle::Draw() const
{
	cout << "[Circle]\n";
}

double Circle::GetArea()
{
	return m_radius*m_radius*3.14;
}

// 정사각형을 상징하는 클래스
class Square : public Shape
{
public:
	virtual double GetArea();
	virtual void Draw() const;

	Square();
	Square(double length);

protected:
	double m_length;
};

Square::Square()
{
	m_length = 100.0f;
}

Square::Square(double length)
: m_length (length)
{
}

void Square::Draw() const
{
	cout << "[Square]\n";
}

double Square::GetArea()
{
	return m_length*m_length;
}
int main()
{
	Rectangle r1(10, 20);
	r1.Draw();
	cout << "r1.area : " << r1.GetArea() << endl;

	Circle c1(5);
	c1.Draw();
	cout << "c1.area : " << c1.GetArea() << endl;

	Square s1(7);
	s1.Draw();
	cout << "s1.area : " << s1.GetArea() << endl;
	
	return 1;
}