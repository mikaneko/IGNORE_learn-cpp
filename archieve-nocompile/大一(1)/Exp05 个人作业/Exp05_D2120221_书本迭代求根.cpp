/***
请输入最大迭代次数:100
请输入误差范围:0.001
-0.520152       2.47985
0.025116        2.50496
0.00122322      2.50619
-3.36274e-06    2.50618
方程的根是：2.50618
***/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int max_calculate = 0;
	double a = 2, b = 3;
	double dx = 0, x1 = 0, x2 = 0, f1 = 0, f2 = 0, epsilon = 0;
	double fa = 0, fb = 0;
	double tmp = 0;
	cout << "请输入最大迭代次数:";
	cin >> max_calculate;
	cout << "请输入误差范围:";
	cin >> epsilon;

	//Validate
	f1 = a * log10(a) - 1;
	f2 = b * log10(b) - 1;
	if (f1 * f2 >= 0) {
		cout << "错误" << endl;
		return 0;
	}

	//Initialize
	if (fabs(f1) < fabs(f2)) {
		x1 = a;
		x2 = b;
	}
	else {
		x1 = b;
		x2 = a;
		tmp = f1;
		f1 = f2;
		f2 = tmp;
	}
	//Calculate
	for (int j = 1; j <= max_calculate; j++) {
		dx = (x1 - x2) * f2 / (f2 - f1);
		cout << dx;
		tmp = x2;
		x2 = x2 + dx;
		x1 = tmp;
		f1 = f2;
		f2 = x2 * log10(x2) - 1;
		cout << '\t' << x2 << endl;
		if((fabs(dx)<epsilon)||(f2==0)){
			cout << "方程的根是：" << x2 << endl;
			return 0;
		}
	}
	cout << "迭代次数过多！" << endl;
	return 1;
}