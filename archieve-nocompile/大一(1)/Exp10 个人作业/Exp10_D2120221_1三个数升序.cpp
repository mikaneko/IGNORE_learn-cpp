#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>

//½»»»a b
void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
//ÉıĞòÅÅĞò
void sort(int& n1, int& n2, int& n3) {
	//Ã°ÅİËã·¨

	//1st
	if (n1 > n2) { swap(n1, n2); }
	if (n2 > n3) { swap(n2, n3); }
	//2nd
	if (n1 > n2) { swap(n1, n2); }
}


//main
int main() {

	int num1, num2, num3;
	srand(time(0));

	num1 = rand() % 50;
	num2 = rand() % 50;
	num3 = rand() % 50;


	cout << num1 << '\t' << num2 << '\t' << num3 << endl;
	sort(num1, num2, num3);
	cout << num1 << '\t' << num2 << '\t' << num3 << endl;


	return 0;
}