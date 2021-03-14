/*
测试结果：
请输入一个整数：
5		if语句输出:不是3的倍数，不是7的倍数
21		if语句输出:是3的倍数，是7的倍数
*/
#include <iostream>
using namespace std;

int main() {

	int input = 0;
	cout << "请输入一个整数：\n";
	cin >> input;
	
	if (input % 3) {
		cout << "不能被3整除\n";
	}
	else cout << "能被3整除\n";

	if (input % 7) {
		cout << "不能被7整除\n";
	}
	else cout << "能被7整除\n";

	return 0;

}