#include <iostream>
using namespace std;

class Vehicle {
public:
	virtual double Fee() = 0; //基类定义纯虚函数
};

class Plane: public Vehicle {
public:
	Plane(double d, double w) {
		distance = d; weight = w;
	}
	~Plane() {}
	double Fee() { //实现虚函数
		return 1.15 * distance + 1.05 * weight;
	}
private:
	double distance, weight;
};

class Ship :public Vehicle {
public:
	Ship(double d, double w) {
		distance = d; weight = w;
	}
	~Ship() {}
	double Fee() {
		return 1.05 * distance + 0.90 * weight;
	}
private:
	double distance, weight;
};

class Car :public Vehicle {
public:
	Car(double d, double w) {
		distance = d; weight = w;
	}
	~Car() {}
	double Fee() {
		return 1.20 * distance + 1.10 * weight;
	}
private:
	double distance, weight;
};

class NewVehicle :public Vehicle { //新交通工具类
public:
	NewVehicle(double d, double w, double df, double wf) { //构造函数赋值四个参数
		distance = d; weight = w; disFee = df; wgtFee = wf;
	}
	~NewVehicle() {}
	double Fee() {
		return disFee * distance + wgtFee * weight;
	}
private:
	double distance, weight, disFee, wgtFee;
};

int main() {
	Plane Airbus(11212, 87968); //构造函数设定距离和重量
	Ship Titanic(12034, 63434);
	Car BMW(14501, 89754);
	NewVehicle Rocket(1273, 6576, 10.40, 11.32);

	cout << "The fee of Airbus: " << Airbus.Fee() << endl;
	cout << "The fee of Titanic: " << Titanic.Fee() << endl;
	cout << "The fee of BMW: " << BMW.Fee() << endl;
	cout << "The fee of Rocket: " << Rocket.Fee() << endl;

	//system("pause");
	return 0;
}