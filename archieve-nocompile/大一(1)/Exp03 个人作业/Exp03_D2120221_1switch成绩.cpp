/*
测试结果：
请输入(0~100)分的成绩：
SCORE	IF-OUT	SWITCH-OUT
100				5
95				5
85				4
75				3
65				2
55				1
0				1
*/


#include <iostream>
using namespace std;

int main() {
	
	int score = 0, outscore = 0;
	cout << "请输入你的百分制分数：\n";
	cin >> score;
	cout << "\n你输入的百分制分数为：" << score << endl;
	outscore = score / 10;

	switch(outscore){

	case 6: cout << "你的五分制分数为2\n"; break; 
	case 7: cout << "你的五分制分数为3\n"; break;
	case 8: cout << "你的五分制分数为4\n"; break;
	case 9: cout << "你的五分制分数为5\n"; break;
	case 10: cout << "你的五分制分数为5\n"; break;
	default : cout << "你的五分制分数为1\n";
	}

	return 0;

}