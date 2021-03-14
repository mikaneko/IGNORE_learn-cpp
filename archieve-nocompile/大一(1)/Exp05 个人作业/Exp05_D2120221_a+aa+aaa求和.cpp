/*
输入a： 5
输入n： 9
		(DEBUG)b[1] = 5
		(DEBUG)b[2] = 55
		(DEBUG)b[3] = 555
		(DEBUG)b[4] = 5555
		(DEBUG)b[5] = 55555
		(DEBUG)b[6] = 555555
		(DEBUG)b[7] = 5555555
		(DEBUG)b[8] = 55555555
		(DEBUG)b[9] = 555555555
结果为：617283945
*/
#include <iostream>
using namespace std;

int main() {
	//主体部分
	int b[20] = { 0 };
	int a = 0;
	int n = 0;
	int sum = 0;
	bool correct = 0;
	while (correct == 0) {
		cout << "输入a(1~9)：\t";
		cin >> a;
		cout << "输入n(1~10)：\t";
		cin >> n;
		if ((a >= 1 && a <= 9) && (n >= 1 && n <= 10) == 1) { correct = 1; }
		else { cout << "输入的a或n有误，请重新输入" << endl << endl; }
	}
	
	b[1] = a;
	for (int i = 1; i <= n; i++) {
		b[i] = (b[i - 1] * 10) + a;
		cout << "\t(DEBUG)b["<<i<<"] = "<<b[i] << endl;
	}
	for (int i = 1; i <= n; i++) {
		sum += b[i];
	}
	cout << "结果为：" << sum << endl;
	return 0;
}