#include <iostream>
using namespace std;

//除find函数外与实验一相同
class MyString {
public:
	MyString(const char* tmp) {
		if (tmp == NULL) {
			str = new char[1];
			str[0] = '\0';
			len = 0;
		}
		else {
			int i = 0;
			while (tmp[i] != '\0')
				i++;
			len = i;
			str = new char[len + 1];
			for (i = 0; i < len; i++)
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
	int find(char, int, int, int);
	MyString mid(int, int);
	MyString& operator=(const MyString&);
	friend MyString operator+(const MyString&, const MyString&);
	friend ostream& operator<<(ostream&, const MyString&);
private:
	char* str;
	int len;
};

int MyString::find(char x, int start = 0, int n = 1, int step = 1) { //从start开始找到第n个与x相等的字符返回其下标，step标记每次查找步长
	int i, cnt = 0;
	for (i = start; i < len && i >= 0; i += step) {
		if (str[i] == x)
			cnt++;
		if (cnt == n)
			return i;
	}
	return -1;
}

MyString MyString::mid(int start, int l) {
	char* tmp = new char[l + 1];
	int i = 0;
	if (len - start < l)
		l = len - start;
	for (i = 0; i < l; i++)
		tmp[i] = str[start + i];
	tmp[i] = '\0';
	return MyString(tmp);
}

int MyString::length() {
	int i;
	if (str[0] == '\0') i = 0;
	else {
		i = 0;
		while (str[i] != '\0') i++;
	}
	len = i;
	return i;
}

ostream& operator<<(ostream &out, const MyString& x) {
	out << x.str;
	return out;
}

MyString& MyString::operator =(const MyString &x) {
	delete[] str;
	len = x.len;
	int i;
	str = new char[len + 1];
	for (i = 0; i < len; i++)
		str[i] = x.str[i];
	str[len] = '\0';
	return *this;
}

MyString operator+(const MyString &s1, const MyString &s2) {
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

class InternetURL {
public:
	InternetURL(const char* tmp) {
		url = tmp;
	}
	MyString GetDomain();
	MyString GetDomainCountry();
	MyString GetDomainType();
private:
	MyString url;
};

MyString InternetURL::GetDomain() { //从头找到第一个为'/'的字符
	int l;
	l = url.find('/');
	MyString tmp;
	if (l == -1)
		l = url.length();
	tmp = url.mid(0, l);
	return tmp;
}

MyString InternetURL::GetDomainCountry() {
	MyString tmp = GetDomain();
	int len = tmp.length();
	int start = tmp.find('.', len - 1, 1, -1); //从末尾找到第一个为'.'字符
	if (len - start - 1 == 2) //长度为2即为country
		tmp = tmp.mid(start + 1, 2);
	else
		tmp = "NULL";
	return tmp;
}

MyString InternetURL::GetDomainType() {
	MyString tmp = GetDomain();
	int len = tmp.length();
	int Cstart = tmp.find('.', len - 1, 1, -1), start; //从末尾找到第一个为'.'字符
	if (len - Cstart - 1 == 2) {
		start = tmp.find('.', len - 1, 2, -1); //从末尾找到第二个为'.'字符
		if (Cstart - start - 1 == 3) //长度为3即为type
			tmp = tmp.mid(start + 1, 3);
		else
			tmp = "NULL";
	}
	else if (len - Cstart - 1== 3) { //长度为3即为type
		start = Cstart;
		tmp = tmp.mid(start + 1, 3);
	}
	else
		tmp = "NULL";
	return tmp;
}

int main() {
	InternetURL URL("www.bit.edu.cn/jwc/080329.html");
	cout << URL.GetDomain() << endl;
	cout << URL.GetDomainCountry() << endl;
	cout << URL.GetDomainType() << endl;

	system("pause");
	return 0;
}