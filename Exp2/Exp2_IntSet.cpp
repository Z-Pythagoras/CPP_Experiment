#include <iostream>
#include <algorithm>
using namespace std;

const int MAXSIZE = 10000;

class IntSet {
public:
	IntSet(int num[], int n) { //初始化集合
		size = n;
		for (int i = 0; i < size; i++)
			set[i] = num[i];
	}
	IntSet(int num) {
		size = 0;
		for (int i = 0; i < MAXSIZE; i++)
			set[i] = num;
	}
	int IsExist(int);
	bool IsEqual(IntSet);
	void RemoveItem(int);
	void AddItem(int);
	void Intersection(IntSet);
	void Union(IntSet);
	void Output();
private:
	int set[MAXSIZE]; //用于存储集合元素
	int size; //集合中元素个数
};

int IntSet::IsExist(int x) { //判断元素是否存在，如果存在返回下标，不存在返回-1
	for (int i = 0; i < size; i++)
		if (x == set[i])
			return i;
	return -1;
}

bool IntSet::IsEqual(IntSet X) { //判断两集合是否相等
	if (size == X.size) {
		for (int i = 0; i < size; i++)
			if (X.IsExist(set[i]) == -1)
				return false;
		return true;
	}
	else
		return false;
}

void IntSet::RemoveItem(int x) { //若存在要删除字符，直接删去，若不存在，提醒不能删除
	if (IsExist(x) == -1)
		cout << x << " is not in the set, so you can not remove it." << endl;
	else {
		size -= 1;
		for (int i = IsExist(x); i < size; i++)
			set[i] = set[i + 1];
	}
}

void IntSet::AddItem(int x) { //若集合中不存在要加入元素且集合内元素个数小于MAXSIZE,则加入元素，反之不加入
	int k = 0;
	if (IsExist(x) == -1) {
		if (size + 1 < MAXSIZE) {
			size += 1;
			set[size - 1] = x;
		}
		else
			cout << "The set is full." << endl;
	}
}

void IntSet::Intersection(IntSet B) { //如果集合元素在B的集合中出现就加入交集C
	IntSet C(0);
	for (int i = 0; i < size; i++)
		if (B.IsExist(set[i]) != -1)
			C.AddItem(set[i]);
	C.Output();
}

void IntSet::Union(IntSet B) { //将两集合非重复元素全部加入并集C
	IntSet C(0);
	for (int i = 0; i < size; i++)
		C.AddItem(set[i]);
	for (int i = 0; i < B.size; i++)
		C.AddItem(B.set[i]);
	C.Output();
}

void IntSet::Output() { //输出集合内元素
	if (size == 0)
		cout << "NULL" << endl;
	else {
		for (int i = 0; i < size; i++)
			cout << set[i] << " ";
		cout << endl;
	}
}

int main() {
	int n, num[MAXSIZE];

	cin >> n; //输入集合A，B进行测试
	for (int i = 0; i < n; i++)
		cin >> num[i];
	IntSet A(num, n);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	IntSet B(num, n);

	cout << "A is:" << endl;
	A.Output();
	cout << "B is:" << endl;
	B.Output();

	if (A.IsExist(3) != -1) //判断元素存在否
		cout << "3 is exist." << endl;
	else
		cout << "3 is not exist." << endl;
	if (A.IsEqual(B)) //判断A，B是否相等
		cout << "A is equal to B." << endl;
	else
		cout << "A is not equal to B." << endl;

	A.RemoveItem(3); //删除元素
	cout << "After remove item A is:" << endl;
	A.Output();
	B.AddItem(10); //加入元素
	cout << "After add item B is:" << endl;
	B.Output();

	cout << "The intersection of A and B:" << endl;
	A.Intersection(B); //求交集
	cout << "The union of A and B:" << endl;
	B.Union(A); //求并集

	return 0;
}
