#define PI 3.14159
#include <cmath>

//圆面积
double area(double radius = 0) {
	return PI * radius * radius;
}
//矩形面积
double area(double a, double b) {
	return a * b;
}
//梯形面积
double area(double a, double b, double h) {
	return(0.5 * (a + b) * h);
}
//三角形面积
double area(double a, double b, double c, int) {
	double s = 0.5 * (a + b + c);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}