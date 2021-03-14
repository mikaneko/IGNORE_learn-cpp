//60
//6
//6
//1
//1
#include <iostream>
using namespace std;


int zuidaGongyueshu(int a, int b);

int main() {

	cout << zuidaGongyueshu(120, 180) << endl;
	cout << zuidaGongyueshu(24, 18) << endl;
	cout << zuidaGongyueshu(18, 24) << endl;
	cout << zuidaGongyueshu(4, 1) << endl;
	cout << zuidaGongyueshu(1, 1) << endl;

	return 0;
}

int zuidaGongyueshu(int a,int b) {
	int max, min;
	if (a > b) { max = a; min = b; }
	else{ max = b; min = a; }


	if (max % min == 0) { return min; }
	else { return zuidaGongyueshu(min, max % min); }
}