#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

bool is_word(char ch) { //判断是否为字母
	if (ch >= 'a'&&ch <= 'z')
		return true;
	else if (ch >= 'A'&&ch <= 'Z')
		return true;
	else
		return false;
}

ll cnt_word(char name[]) { //计算单词数量
	ifstream file(name); //读取文件
	string str;

	ll cnt = 0;
	while (getline(file, str)) { //从文件中按行读取
		if (is_word(str[0])) //每行第一个字符若为字母，单词数+1
			cnt++;
		for (ll i = 1; i < str.length() - 1; i++) //遍历每一行
			if (str[i] == ' ' && is_word(str[i + 1])) //若第一个字符为空格第二个字符为字母单词数+1
				cnt++;
	}
	file.close(); 
	return cnt; //返回单词数
}

int main() {
	char filename[500];    
    ll wordsNum;

	cin >> filename; //读取文件路径
	wordsNum = cnt_word(filename); //计算单词数
	cout << wordsNum << endl;

	system("pause");
	return 0;
}
