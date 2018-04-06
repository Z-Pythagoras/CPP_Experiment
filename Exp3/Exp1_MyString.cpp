#include <iostream>
using namespace std;

class MyString {
public:
	MyString(const char *tmp) {
		if (tmp == NULL) {
			str = new char[1];
			str[0] = '\0';
			len = 0;
		}
		else {
			int i = 0;
			while (tmp[i] != '\0') //求字符串长度
				i++;
			len = i;
			str = new char[len + 1];
			for (i = 0; i < len; i++) //字符串逐个赋值
				str[i] = tmp[i];
			str[len] = '\0';
		}
	}
	MyString() {
		str = new char[1];
		str[0] = '\0';
		len = 0;
	}
	int length();
	int find(char);
	MyString mid(int, int);
	MyString& operator=(const MyString&);
	friend MyString operator+(const MyString&, const MyString&);
	friend ostream& operator<<(ostream&, const MyString&);
private:
	char* str;
	int len;
};

int MyString::find(char x) { //从开始找第一个字符x，返回字符位置
	int i = 0;
	for (i = 0; i < len; i++)
		if (str[i] == x)
			return i;
	return -1;
}

MyString MyString::mid(int start, int l) { //从start开始截取长为l的字符串
	char* tmp = new char[l + 1];
	int i = 0;
	if (len - start < l)
		l = len - start;
	for (i = 0; i < l; i++)
		tmp[i] = str[start + i];
	tmp[i] = '\0';
	return MyString(tmp);
}

int MyString::length() { //计算字符串长度
	int i;
	if (str[0] == '\0') i = 0;
	else {
		i = 0;
		while (str[i] != '\0') i++;
	}
	len = i;
	return i;
}

ostream& operator<<(ostream &out, const MyString& x) { //重载<<
	out << x.str;
	return out;
}

MyString& MyString::operator =(const MyString &x) { //重载=
	delete[] str;
	len = x.len;
	int i;
	str = new char[len + 1];
	for (i = 0; i < len; i++)
		str[i] = x.str[i];
	str[len] = '\0';
	return *this;
}

MyString operator+(const MyString &s1, const MyString &s2) { //重载+
	MyString tmp;
	tmp.len = s1.len + s2.len;
	tmp.str = new char[tmp.len + 1];
	int i;
	for (i = 0; i < s1.len; i++)
		tmp.str[i] = s1.str[i];
	for (i = 0; i < s2.len; i++)
		tmp.str[s1.len + i] = s2.str[i];
	tmp.str[tmp.len] = '\0';
	return tmp;
}

int main() {
	MyString s1("China"), s2;
	s2 = "Love";
	cout << "I" + s2 + s1 << endl;

	int pos = s1.find('a');
	cout << pos << endl;

	int a = 1, b = 10;
	MyString my = s2.mid(a, b);
	cout << my << endl;

	system("pause");
	return 0;
}