#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class LINT {
public:
	LINT(string tmp = "0\0") {
		num = tmp;
	}
	friend ostream& operator<<(ostream&, const LINT&);
	LINT Add(const LINT);
private:
	string num;
};

LINT LINT::Add(const LINT B) {
	string tmpA(num.rbegin(), num.rend()); //字符串反向
	string tmpB(B.num.rbegin(), B.num.rend());
	string tmp;
	int i;
	int len = max(tmpA.size(), tmpB.size()) + 1;
	for (i = tmpA.size(); i < len; i++) //补0使字符串对齐
		tmpA += '0';
	for (i = tmpB.size(); i < len; i++)
		tmpB += '0';
	for (i = 0; i < len; i++)
		tmp += '0';
	
	for (i = 0; i < len - 1; i++) { //从头逐位相加
		tmp[i] += tmpA[i] - '0' + tmpB[i] - '0';
		if (tmp[i] - '0' >= 10) {
			tmp[i] -= 10;
			tmp[i + 1] = '1';
		}
	}
	string ans(tmp.rbegin(), tmp.rend()); //字符串反向
	if (ans[0] == '0') //去掉开头的0
		ans.erase(ans.begin());

	return LINT(ans);
}

ostream& operator<<(ostream &out, const LINT& x) {
	out << x.num;
	return out;
}

int main() {
	LINT numA("1");
	LINT numB("99999");
	
	cout << numA.Add(numB) << endl;

	system("pause");
	return 0;
}