#include <stdio.h>

struct Shape
{
	.......
	
};

// 사각형을 상징하는 구조체
struct Rectangle
{
	.......

	double m_width;
	double m_height;
};

void R_Draw()
{
	printf("[Rectangle]\n");
}

double R_GetArea(double m_width, double m_height)
{
	return m_width*m_height;
}

// 원을 상징하는 구조체
struct Circle
{
	........

	double m_radius;
};

void C_Draw()
{
	printf("[Circle]\n");
}

double C_GetArea(double m_radius)
{
	return m_radius*m_radius*3.14;
}

// 정사각형을 상징하는 구조체
struct Square
{
	........

	double m_length;
};

void S_Draw()
{
	printf("[Square]\n");
}

double S_GetArea(double m_length)
{
	return m_length*m_length;
}

int main()
{
	.............
	
	
	
	
	
	return 1;
}