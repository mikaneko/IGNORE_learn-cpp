/*
测试结果：
请输入(0~100)分的成绩：
SCORE	IF-OUT	SWITCH-OUT
100		5
95		5
85		4
75		3
65		2
55		1
0		1
*/
#include <iostream>
using namespace std;

int main() {

	double score = 0;
	cout << "输入你的百分制成绩：\n";
	cin >> score;
	cout << "\n你输入的百分制成绩是：" << score << endl;
	if (score >= 90.0) {
		cout << "你的成绩是5" << endl;
	}
	else if (score >= 80.0) {
		cout << "你的成绩是4" << endl;
	}
	else if (score >= 70.0) {
		cout << "你的成绩是3" << endl;
	}
	else if (score >= 60.0) {
		cout << "你的成绩是2" << endl;
	}
	else cout << "你的成绩是1" << endl;

	return 0;

}