	/*
	请输入大小写文字串
	全部转换为大写
	Unstable Hello My Cpp6666
	UNSTABLE HELLO MY CPP6666
	请输入大小写文字串
	全部转换为小写
	Unstable Hello My Cpp6666
	unstable hello my cpp6666
	*/
#include <iostream>
using namespace std;
 
char low_to_cap(char);
char cap_to_low(char);

int main() {
	cout << "请输入大小写文字串" << endl;
	cout << "全部转换为大写" << endl;
	char str1[100] = {0};
	cin.getline(str1,90);
	for (int i = 0; i < 90; i++) {
		str1[i] = low_to_cap(str1[i]);
	}
	cout << str1 << endl;

	cout << "请输入大小写文字串" << endl;
	cout << "全部转换为小写" << endl;
	char str2[100] = { 0 };
	cin.getline(str2, 90);
	for (int i = 0; i < 90; i++) {
		str2[i] = cap_to_low(str2[i]);
	}
	cout << str2 << endl;
	return 0;
}

char low_to_cap(char a) {
	if (a >= 'a' && a <= 'z') {
		a = a - ('a' - 'A');
	}
	return a;
}

char cap_to_low(char a) {
	if (a >= 'A' && a <= 'Z') {
		a = a + ('a' - 'A');
	}
	return a;
}
