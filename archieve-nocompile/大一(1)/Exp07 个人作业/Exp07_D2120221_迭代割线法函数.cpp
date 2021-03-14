
#include <iostream>
#include <cmath>
using namespace std;


double f(double);
double the_algorithm(int, double);

int main() {
	int maxcal;
	double eps;
	cout << "请输入最大迭代次数" << endl;
	cin >> maxcal;
	cout << "请输入误差范围" << endl;
	cin >> eps;
	cout << the_algorithm(maxcal, eps) << endl;

	return 0;
}

double f(double a) {
	return (a * log10(a)) - 1;
}

/*
请输入最大迭代次数
8
请输入误差范围
0.0001
2.50777


*/

double the_algorithm(int max_calculate_count, double epsilon) {
	//a,b为初值
	double a = 2, b = 3;
	double x1 = 0, x2 = 0, x3 = 0;
	if (fabs(f(a)) > fabs(f(b))) {
		x1 = a;
		x2 = b;
	}
	else {
		x1 = b;
		x2 = a;
	}
	for (int i = 0; i < max_calculate_count;i++) {
		if (((x1 - x2) / (f(x2) - f(x1)) * f(x2)<epsilon )) {
			break;
		}
		x3 = x2 + (x1 - x2) / (f(x2) - f(x1)) * f(x2);
		x1 = x2;
		x2 = x3;
		if (x3 == 0) {
			break;
		}
		if (i == max_calculate_count - 1) {
			cout << "迭代次数过多" << endl;
			return 0;
		}
	}
	
	return x3;
	}
