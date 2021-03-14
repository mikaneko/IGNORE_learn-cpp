//1
//2
//3
//5
//1
//2
//3
//5
//1010
//1111111111111110
//1010
//1111111111111110
#include <iostream>
using namespace std;

int intpow(int, int);

void ten2two(int);
int feibo(int);
int old_feibo(int);
void old_ten2two(int a);

int main() {

	//递归feibo
	cout << feibo(2) << endl;
	cout << feibo(3) << endl;
	cout << feibo(4) << endl;
	cout << feibo(5) << endl;
	//迭代feibo
	cout << old_feibo(2) << endl;
	cout << old_feibo(3) << endl;
	cout << old_feibo(4) << endl;
	cout << old_feibo(5) << endl;
	//递归10转2
	ten2two(10);
	cout << endl;
	ten2two(65535-1);
	cout << endl;
	//迭代10转2
	old_ten2two(10);
	cout << endl;
	old_ten2two(65535 - 1);
	cout << endl;
	return 0;
}

int intpow(int a, int b) {
	int MATH_temp = 1;
	for (int i = 1; i <= b; i += 1) {
		MATH_temp = MATH_temp * a;
	}
	return MATH_temp;
}
void ten2two(int a) {
	if (a == 0) { return; }
	else {
		ten2two(a / 2);
		cout << a%2 ;
		return;
	}
}
int feibo(int a) {
	if (a == 1 || a == 2) { return 1; }
	else { return feibo(a - 1) + feibo(a - 2); }
}
int old_feibo(int a) {
	if (a == 1 || a == 2) { return 1; }

	int n = 1;


	int a1 = 1, a2 = 1;
	while (n < a-1) {
		
		int tmp = a2;
		a2 = a1 + a2;
		a1 = tmp;
		
		//cout << a2 << endl;
		n++;
	}
	return a2;
}
void old_ten2two(int a) {
	bool haveone = 0;
	for (int i = 30; i >= 0; i -= 1) {
		if (a >= (intpow(2, i))) {
			cout << '1'; 
			a -= intpow(2, i);
			haveone = 1;
		}
		else {
			if (haveone == 1) { cout << '0'; };
		}
	}
	return;
}
