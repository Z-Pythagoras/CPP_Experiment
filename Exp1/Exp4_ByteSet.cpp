#include <iostream>
using namespace std;

void ByteSet(void* p, int len, int value) {
	unsigned char* ch = static_cast<unsigned char*>(p);
	int cntByte = len * sizeof(int); //由长度得到Byte数量

	for (int i = 0; i < cntByte; i++) //将每Byte赋值为value
		*(ch + i) = value;
}

int main() {
	int num[10005];
	int data, l; //设置的数据，设置的长度
	void *loc = static_cast<void*>(num);

	cin >> l >> data;
	for (int i = 0; i < l; i++) //两次输出对比结果
		cout << num[i] << ' ';
	cout << '\n';
	ByteSet(loc, l, data);
	for (int i = 0; i < l; i++)
		cout << num[i] << ' ';
	cout << '\n';

	system("pause");
	return 0;
}