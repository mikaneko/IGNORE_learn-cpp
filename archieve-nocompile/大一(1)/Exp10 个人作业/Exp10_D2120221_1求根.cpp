#include<iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include<cmath>
const double eps = 0.00001;



void sloveQ(double a, double b, double c, double& delta, double& r1, double& r2) {
	delta = b * b - 4 * a * c;
	if (delta > eps) {
		r1 = (-b + sqrt(delta)) / 2 * a;
		r2 = (-b - sqrt(delta)) / 2 * a;
	}
	if (delta < -eps) {
		r1 = -1;
		r2 = -1;
	}
	if (fabs(delta) <= eps) {
		r1 = -b / 2 * a;
		r2 = -b / 2 * a;
	}
}



int main() {
	double a, b, c;
	srand(time(0));
	a = (rand() % 1000) / 100.0;

	if (fabs(a) <= eps) { return -1; }//fatel error

	b = (rand() % 1000) / 100.0;
	c = (rand() % 1000) / 100.0;
	double delta, r1, r2;

	cout << a << '\t' << b << '\t' << c << endl;

	sloveQ(a, b, c, delta, r1, r2);
	
	if (delta > eps) {
		cout << r1 << '\t' << r2 << endl;
	}
	if (delta < -eps) {
		cout <<"no slove"<< endl;
	}
	if (fabs(delta) <= eps) {
		cout << r1 << endl;
	}




	return 0;
}