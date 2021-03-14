/*
测试结果：
请输入一个整数：
5		switch语句输出:不是3的倍数，不是7的倍数
21		switch语句输出:是3的倍数，是7的倍数
*/
#include <iostream>
using namespace std;

int main() {

	int input = 0, input3 = 0, input7 = 0;
	cout << "请输入一个整数：\n";
	cin >> input;
	input3 = input % 3;
	input7 = input % 7;

	
	switch (input3) {
	case 0:cout << "能被3整除\n"; break;
	default:cout << "不能被3整除\n";
	}

	switch (input7) {
	case 0:cout << "能被7整除\n"; break;
	default:cout << "不能被7整除\n";
	}

	return 0;

}