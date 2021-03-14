/*
效率极低。。

153
370
371
407
3位自幂数结束。


计算n位自幂数
输入n：8
24678050
24678051
88593477

*/
#include <iostream>
using namespace std;

//定义正整数的乘方（MATHa为底数，MATHb为指数）
int MATH_intpower(int MATHa, int MATHb) {
	int MATH_temp = 1;
	for (int i = 1; i <= MATHb; i++) {
		MATH_temp *= MATHa;
	}
	return MATH_temp;
}


int main() {
	//3位自幂数
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				if ((a * 100 + b * 10 + c) == (a * a * a + b * b * b + c * c * c)) { cout << a * 100 + b * 10 + c << endl; }
			}
		}
	}
	cout << "3位自幂数结束。\n";


	//n位自幂数
	int n = 0;
	cout << "\n\n计算n位自幂数\n";
	cout << "输入n：";
	cin >> n;
	int tmp[20] = { 0 };
	int sum = 0;
	for (int i = MATH_intpower(10, n - 1); i < MATH_intpower(10, n); i++) {
		int contrast = i;
		int calculate = i;

		for (int h = 1; h <= n; h++) { tmp[h] = (calculate % (MATH_intpower(10, h)) / (MATH_intpower(10, h - 1))); calculate -= calculate % (MATH_intpower(10, h)); }
		for (int e = 1; e <= n; e++) { tmp[e] = MATH_intpower(tmp[e], n); }
		for (int f = 1; f <= n; f++) { sum += tmp[f]; }

		if (contrast == sum) { cout << contrast << endl; }
		sum = 0;
	}

	return 0;
}