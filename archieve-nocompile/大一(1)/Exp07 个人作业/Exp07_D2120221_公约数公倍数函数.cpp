//定义枚举法 求最小公倍数
//请输入第一个数
//4
//请输入第二个数
//6
//12
//定义枚举法 求最大公约数
//请输入第一个数
//4
//请输入第二个数
//6
//2
//欧几里得辗转相除法 求最大公约数
//请输入第一个数
//4
//请输入第二个数
//6
//2
#include <iostream>
using namespace std;

int ZuiXiaoGongBeishu_DEFINITION(int, int);
int ZuiDaGongYueShu_DEFINITION(int, int);
int ZuiDaGongYueShu_OUJILIDE(int, int);

int main() {
	int a1, b1, a2, b2, a3, b3;
	cout << "定义枚举法 求最小公倍数" << endl;
	cout << "请输入第一个数" << endl;
	cin >> a1;
	cout << "请输入第二个数" << endl;
	cin >> b1;
	int o1 = ZuiXiaoGongBeishu_DEFINITION(a1, b1);
	cout << o1 << endl;

	cout << "定义枚举法 求最大公约数" << endl;
	cout << "请输入第一个数" << endl;
	cin >> a2;
	cout << "请输入第二个数" << endl;
	cin >> b2;
	int o2 = ZuiDaGongYueShu_DEFINITION(a2, b2);
	cout << o2 << endl;

	cout << "欧几里得辗转相除法 求最大公约数" << endl;
	cout << "请输入第一个数" << endl;
	cin >> a3;
	cout << "请输入第二个数" << endl;
	cin >> b3;
	int o3 = ZuiDaGongYueShu_OUJILIDE(a3, b3);
	cout << o3 << endl;
	return 0;
}


int ZuiXiaoGongBeishu_DEFINITION(int a, int b) {
	int max = 0, testnum = 1;

	if (a >= b) { max = a; }
	else { max = b; }
	testnum = max;

	while (1) {
		if (testnum % a == 0 && testnum % b == 0) {
			return testnum;
		}
		testnum++;
	}
}

int ZuiDaGongYueShu_DEFINITION(int a, int b) {
	int min = 0, testnum = 1;
	if (a >= b) { min = b; }
	else { min = a; }
	testnum = min;

	while (1) {
		if (a % testnum == 0 && b % testnum == 0) {
			return testnum;
		}
		testnum--;
	}
}

int ZuiDaGongYueShu_OUJILIDE(int a, int b) {
	int max = 0;//ab中的大值
	int min= 0;//ab中的小值
	int mob = 0;//余数1

	if (a >= b) { max = a; min = b; }
	else { max = b; min = a; }
	while (1) {
		mob = max % min;
		if (mob == 0) { break; }
		max = min;
		min = mob;
	}
	return min;
}
