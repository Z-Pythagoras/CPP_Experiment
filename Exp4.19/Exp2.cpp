#include <iostream>
#include <string>
using namespace std;

const int MAXL = 9999;

class Student {
public:
	Student(string n = "NULL", unsigned int a = 0) { //初始化学生姓名为“NULL”
		name = n;
		age = a;
	}
	friend ostream& operator<<(ostream& os, const Student& stu) { //重载<<输出学生姓名和年龄
		os << stu.name << " " << stu.age;
		return os;
	}
	bool operator==(const Student& d) { //重载==判定对象是否相同
		return name == d.name && age == d.age;
	}
private:
	string name;
	unsigned int age;
};

template<class Type, const int Volume>
class List;

template<class Type>
class Node {
	friend class List<Type, MAXL>; //定义友元类
public:
	Node() : data(Type()), next(NULL) { cnt = 0; }
	Node(Type d, Node<Type>* n = NULL) : data(d), next(n) { cnt = 0; } //重载构造函数
	~Node() {}
private:
	Type data; //存储结点数据
	int cnt; //存储结点个数
	Node<Type>* next; //结点指针
};

template<class Type, const int Volume>
class List {
public:
	List() {
		head = last = Newnode();
	}
	~List() { //析构函数删除结点
		while (head->cnt) //结点个数不为0时，删除节点
			Delete();
	}
public:
	void Add(const Type &x); //添加
	void Show(); //全部输出
	void Delete(); //删除
	Type operator[](int); //重载[]访问元素
	Node<Type>* Newnode(Type x = Type()) { //创建新结点
		Node<Type>* p = new Node<Type>(x);
		return p;
	}
private:
	Node<Type>* head; //头指针
	Node<Type>* last; //当前指针
};

template<class Type, const int Volume>
void List<Type, Volume>::Add(const Type &x) {
	Node<Type> *s = Newnode(x);
	last->next = s;
	last = s;
	head->cnt++; //结点个数+1
}

template<class Type, const int Volume>
void List<Type, Volume>::Show() {
	Node<Type> *p = head->next;
	while (p != NULL) { //输出尾节点前的所有数据
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<class Type, const int Volume>
void List<Type, Volume>::Delete() {
	if (head->cnt == 0) //如果节点数>0，删除尾结点
		return;
	Node<Type> *p = head;
	while (p->next != last)
		p = p->next;
	delete p->next;
	p->next = NULL;
	last = p;
	head->cnt--; //节点个数-1
}

template<class Type, const int Volume>
Type List<Type, Volume>::operator[](int i) { //重载[]
	Node<Type> *p = head->next;
	if (i >= head->cnt) //判定下标i是否越界
		return Type(); //越界返回空值
	for (int j = 0; j < i && p->next != NULL; j++) //遍历找到下标为i的结点
		p = p->next;
	return p->data; //返回结点数据
}

int main() {
	Student s1("Joan", 22), s2("John", 19);
	List<Student, MAXL> listStudent;
	listStudent.Add(s1);
	listStudent.Add(s2);
	//listStudent.Show();
	//listStudent.Delete();
	//listStudent.Show();
	if (listStudent[0] == listStudent[1])
		cout << "Equal." << endl;
	else
		cout << "Not equal." << endl;

	//system("pause");
	return 0;
}
