#include <iostream>
using namespace std;

long com(int, int);

int main() {
	int a, b;
	cout << "calculate C(sum,sel)" << endl;
	cin >> a >> b;
	cout << com(a, b) << endl;
	return 0;
}


long com(int sum, int sel) {
	if ( sel == 0) { return 1; }
	else return com(sum, sel - 1)*(sum-(sel-1))/sel;
}