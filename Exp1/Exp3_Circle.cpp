#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Circle {
public:
	double x, y; //圆心坐标
	double r; //半径
	double dis; //两圆心距离
	void Distance(Circle B); //计算距离
	void Relationship(Circle B); //判断两个圆的关系
};

void Circle::Distance(Circle B) {
	dis = sqrt((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
}

void Circle::Relationship(Circle B) {
	double rmis; //圆半径之差
	rmis = r - B.r;
	rmis = rmis > 0 ? rmis : -rmis;
	if (dis > r + B.r || dis < rmis) //分离
		cout << "seperation" << "\n";
	else if (dis == r + B.r) //外切
		cout << "externally tangent" << "\n";
	else if (dis == rmis) //内切
		cout << "internally tangent" << "\n";
	else //相交
		cout << "intersection" << "\n";
}

int main() {
	Circle A, B;
	cin >> A.x >> A.y >> A.r >> B.x >> B.y >> B.r; 
	A.Distance(B); 
	cout << A.dis << endl;
	A.Relationship(B);

	system("pause");
	return 0;
}
