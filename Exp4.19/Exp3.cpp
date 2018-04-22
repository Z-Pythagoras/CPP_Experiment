#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
	virtual double Area() = 0;  
	//virtual double Volume() = 0; //三角形和圆形无法求体积，故修改为求周长函数
	virtual double Circum() = 0;
};

class Circle : public Shape {
public:
	Circle(double x = 0, double p = 3.1415926) { //设定默认参数，PI = 3.1415926
		r = x; PI = p;
	}
	~Circle() {}
	double Area() {
		return PI * r * r;
	}
	double Circum() {
		return 2 * PI *r;
	}
private:
	double r, PI;
};

class Triangle : public Shape {
public:
	Triangle(double x = 0, double y = 0, double z = 0) {
		a = x; b = y; c = z;
	}
	~Triangle() {}
	double Area() {
		p = (a + b + c) / 2;
		if (a + b > c && a + c > b && b + c > a) //判定三条边是否构成三角形
			return sqrt(p*(p - a)*(p - b)*(p - c)); //使用海伦公式求面积
		else
			return -1; //不是三角形返回-1
	}
	double Circum() {
		if (a + b > c && a + c > b && b + c > a) //判定三条边是否构成三角形
			return a + b + c;
		else
			return -1; //不是三角形返回-1
	}
private:
	double a, b, c, p;
};

class CAD {
private:
	Shape& shape;
public:
	CAD(Shape& S) : shape(S) { }
	double Area() { 
		return shape.Area();
	}
	double Circum() {
		return shape.Circum();
	}
};

int main() {
	Circle Cr(1, 3.14);
	Triangle Tr(3, 4, 5);

	CAD CadC(Cr), CadT(Tr); //创建CAD对象
	cout << "The area of Cr1: " << CadC.Area() << endl;
	cout << "The Circum of Cr1: " << CadC.Circum() << endl;
	cout << "The area of Tr1: " << CadT.Area() << endl;
	cout << "The Circum of Tr1: " << CadT.Circum() << endl;

	//system("pause");
	return 0;
}