#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Frame {
public:
	Frame() {
		ID = "\0";
		weight = 0;
	}
	friend istream& operator>>(istream& in, Frame& x); //重载输入
	string ShowID() { //定义接口访问ID
		return ID;
	}
private:
	string ID;
	int weight;
};

istream& operator>>(istream& in, Frame& x) {
	in >> x.ID >> x.weight;
	return in;
}

class Cardoor {
public:
	Cardoor() {
		Cnum = 0;
		color = "\0";
	}
	friend istream& operator>>(istream& in, Cardoor& x);
	int ShowCnum() {
		return Cnum;
	}
private:
	int Cnum;
	string color;
};

istream& operator>>(istream& in, Cardoor& x) {
	in >> x.Cnum >> x.color;
	return in;
}

class Tyre {
public:
	Tyre() {
		Tnum = 4;
	}
	friend istream& operator>>(istream& in, Tyre& x);
	int showTnum() {
		return Tnum;
	}
private:
	int Tnum;
};

istream& operator>>(istream& in, Tyre& x) {
	in >> x.Tnum;
	return in;
}

class Vehicle {
public:
	friend ostream& operator<<(ostream& out, Vehicle& x); //重载输出
	Frame f; //调用已定义类
	Cardoor c;
	Tyre t;
};

ostream& operator<<(ostream& out, Vehicle& x) {
	out << x.f.ShowID() << " " << x.c.ShowCnum() << " " << x.t.showTnum() << endl;
	return out;
}

int main() {
	Vehicle v;
	cin >> v.f; cin >> v.c; cin >> v.t;
	cout << v;

	return 0;
}
