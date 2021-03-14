/*
(solve)1.96887
(solve)-3.16195
(solve)1.96887
(solve)-3.16195
(solve)1.96887
(solve)-1.96887
(solve)3.16195
(solve)-1.96887
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {

	//可编辑部分
	const double pi = 3.141592;
	double ep = 1e-5;
	double x1 = 0;
	double x2 = 0;
	double step = 0.2;
	double start = 8 * pi;
	int flag = 1;

	//input

	//main

	while(flag<=8){
		x1 = start;
		x2 = start + 10 * ep;
		while (1) {
			x2 = ((x1 * x1) - 10 * (x1 * sin(x1) + cos(x1))) / (2 * x1 - 10 * sin(x1));
			if (fabs(x1 - x2) <= ep)break;
			x1 = x2;
			//cout << "(debug-calculate)" << x2 << endl;
		}
		cout << "(solve)" << x2 << endl;
		start /= -2;
		flag++;

	}

	return 0;
}