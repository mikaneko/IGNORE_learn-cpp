/*
输入	输出
x=0		y=0
x=1		y=1
x=10	y=19
*/
#include <iostream>
using namespace std;

int main() {

	double x = 0, y = 0;
	cout << "函数y = x,x<1\n\t2x-1,1<=x<=10\n\t3x-11,x>=10\n";
	cout << "输入变量x\n";
	cin >> x;
	cout << "你输入的x为" << x << endl;

	if (x < 1) { y = x; }
	else if (x <= 10) { y = 2 * x - 1; }
	else y = 3 * x - 11;
	
	cout << "y = " << y << endl;

	return 0;

}