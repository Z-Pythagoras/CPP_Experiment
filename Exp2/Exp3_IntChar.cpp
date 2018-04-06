#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class IntChar {
public:
	IntChar(char input[]) {
		num = 0;
		for (int i = 0; i < strlen(input); i++) //使用移位运算将字符串逐字符存储在int型数中
			num += input[i] << (8 * (3 - i)); //将第0个字符左移24位，第1个字符左移16位，第2个字符左移8位，第3个字符不移位
	}
	void ASC_Print();
	void Binary_Print();
	void Int_Print();
private:
	int num;
};

void IntChar::ASC_Print() {
	int tmp = num;

	char ASC[5] = { '\0' };
	for (int i = 0; i < 4; i++) {
		ASC[3 - i] = tmp & 255; //从后向前提取字符，每次都与255做按位与运算，得到字符ASCII码
		tmp = tmp >> 8; //数字右移8位，提取下一个字符
	}
	cout << ASC << endl;
}

void IntChar::Binary_Print() {
	int tmp = num;
	char Binary[33] = { '\0' };

	for (int i = 0; i < 32; i++) {
		Binary[31 - i] = (tmp & 1) + '0'; //从后向前逐位提取二进制数，每次都与1做按位与运算，得到每位二进制数0或1，并以字符串形式存储
		tmp = tmp >> 1; //数字右移1位，提取下一位二进制数
	}
	for (int i = 0, j = 3; i <= 31; i++) {
		cout << Binary[i]; //逐位输出二进制数
		if (i == j) {
			cout << " "; //每输出4位输出一个空格
			j += 4;
		}
	}
	cout << endl;
}

void IntChar::Int_Print() {
	cout << num << endl;
}

int main() {
	char text[5];
	cin >> text;

	IntChar IC(text); //调用构造函数
	IC.ASC_Print();
	IC.Binary_Print();
	IC.Int_Print();

	return 0;
}
