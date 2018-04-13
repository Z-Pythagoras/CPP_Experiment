#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class CSqlStatement {
public:
	CSqlStatement(const char*);
	CSqlStatement& operator=(const CSqlStatement&);
	void SetAttribute(string, string);
	void ExecuteSql();
private:
	string str, substr[6]; //输入字符串，字符串子串
	bool flag = true; //输入是否正确
};

CSqlStatement::CSqlStatement(const char* x) {
	str = "\0"; //初始化字符串
	if (x != NULL)
		str = x;
	string tmp = str;
	for (int i = 0; i < 6; i++) { //初始化字符字串，按问号位置分割子串
		int j = tmp.find("?");
		substr[i] = tmp.substr(0, j) + "\0";
		tmp = tmp.substr(j + 1) + "\0";
	}
}

CSqlStatement& CSqlStatement::operator=(const CSqlStatement& x) {
	str = x.str;
	return *this;
}

void CSqlStatement::SetAttribute(string num, string index) {
	int no = 0;
	if (num.length() == 0) { //处理输入指令
		flag = false; return;
	}
	else if (num.length() == 1) {
		if (num[0] >= '1' && num[0] <= '9')
			no = num[0] - '0';
		else {
			flag = false; return;
		}
	}
	else { //排除错误输入，例如“555”，判定为5，“556”，判定为错误
		for (int i = 1; i < num.length(); i++) {
			if (num[i] != num[0]) {
				flag = false; return;
			}
			no = num[0] - '0';
		}
		cout << "Input warning" << endl;
	}
	if (no >= 1 && no <= 5) //在正确位置的子串后拼接操作
		substr[no - 1] += index + "\0";
	else {
		flag = false; return;
	}
}

void CSqlStatement::ExecuteSql() {
	if (!flag)
		cout << "Input error" << endl;
	else { //将子串拼接
		string tmp = "\0";
		for (int i = 0; i < 6; i++)
			tmp += substr[i];
		cout << tmp << endl;
	}
}

int main() {
	CSqlStatement sql = "select ?, ? from student where gender = ? and height >= ? order by ?";
	sql.SetAttribute("3", "female");
	sql.SetAttribute("4", "165");
	sql.SetAttribute("1", "SID");
	sql.SetAttribute("2", "Name");
	sql.SetAttribute("5", "gender");
	sql.ExecuteSql();

	return 0;
}
