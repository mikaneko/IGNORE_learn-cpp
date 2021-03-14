/*
*定义枚举法 求最大公约数
请输入第一个数
24
请输入第二个数
18
最大公约数是 6
==================
定义枚举法 求最小公倍数
请输入第一个数
24
请输入第二个数
18
最小公倍数 72
==================
欧几里得辗转相除法 求最大公约数
请输入第一个数
24
请输入第二个数
18
最大公约数是 6
*/
#include <iostream>
using namespace std;

int main() {

	//（定义枚举法）最大公约数
	int a = 0, b = 0;
	int min = 0;//ab中的小值
	int testnum = 1;
	bool doFind = 0;
	cout << "定义枚举法 求最大公约数" << endl;
	cout << "请输入第一个数" << endl;
	cin >> a;
	cout << "请输入第二个数" << endl;
	cin >> b;
	
	if (a >= b) { min = b; }
	else { min = a; }
	testnum = min;

	while (doFind == 0) {
		if (a % testnum == 0 && b % testnum == 0) { 
			doFind = 1;
			cout << "最大公约数是 " << testnum << endl;
		}
		testnum--;
	}

	cout << "==================" << endl;
	//（定义枚举法）最小公倍数
	int a2 = 0, b2 = 0;
	int max2 = 0;//ab中的大值
	int testnum2 = 1;
	bool doFind2 = 0;
	cout << "定义枚举法 求最小公倍数" << endl;
	cout << "请输入第一个数" << endl;
	cin >> a2;
	cout << "请输入第二个数" << endl;
	cin >> b2;

	if (a2 >= b2) { max2 = a2; }
	else { max2 = b2; }
	testnum = max2;

	while (doFind2 == 0) {
		if (testnum2 % a2 == 0 && testnum2 % b2 == 0) {
			doFind2 = 1;
			cout << "最小公倍数 " << testnum2 << endl;
		}
		testnum2++;
	}


	cout << "==================" << endl;


	//（欧几里得辗转相除法）最大公约数
	int a3 = 0, b3 = 0;
	int max3 = 0;//ab中的大值
	int min3 = 0;//ab中的小值
	int mob = 0;//余数1

	cout << "欧几里得辗转相除法 求最大公约数" << endl;
	cout << "请输入第一个数" << endl;
	cin >> a3;
	cout << "请输入第二个数" << endl;
	cin >> b3;

	if (a3 >= b3) { max3 = a3; min3 = b3; }
	else { max3 = b3; min3 = a3; }
	while (1) {
		mob = max3 % min3;
		if (mob == 0) { break; }
		max3 = min3;
		min3 = mob;
	}
	cout << "最大公约数是 " << min3 << endl;


	return 0;
}