#include <iostream>
using namespace std;

class Output { //使用类的构造函数和析构函数达到输出字符串的目的
public:
	Output() {
        cout << "Initialize" << endl;
    }
	~Output() {
        cout << "Clear up" << endl;
    }
};

Output yea;

int main() //由于编译器不支持void main()，故将void更改为int
{
	cout << "Hello World!\n";
}
