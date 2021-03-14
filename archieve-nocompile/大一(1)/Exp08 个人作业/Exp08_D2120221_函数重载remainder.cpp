/*

*/

#include <iostream>
using namespace std;

//四舍五入取整函数round(double)
double round(double r)
{
	return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

int remainder(int a, int b) {
	return a % b;
}
double remainder(double a, double b) {
	int a1 = round(a);
	int a2 = round(b);
	return a1 % a2;
}

int main() {
	cout<<remainder(12, 7)<<endl;
	cout << remainder(12.5, 3.5) << endl;
	cout << remainder(12.5, 3) << endl;
	return 0;
}