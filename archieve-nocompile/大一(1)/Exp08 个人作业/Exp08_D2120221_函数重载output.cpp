/*

*/

#include <iostream>
#include <iomanip>
using namespace std;

enum JINZHI{ten,eight,sixteen};

void output(int a,JINZHI b=ten) {
	switch (b){
	case ten:cout << "[int10]" << dec << a << endl; break;
	case eight:cout << "[int8]" << oct << a << endl; break;
	case sixteen:cout << "[int16]" << hex << a << endl; break;
	}
		
}
void output(double a ,int prec = 6) {
	cout << "[double]" << setprecision(prec) << a << endl;
}
void output(char str[]) {
	cout << "[charstr]" << str << endl;
}

int main() {
	output(12345);
	output(12345,sixteen);
	output(12345,eight);
	output(1.2345678901234);
	output(1.2345678901234,4);
	char strr[] = "nihaoya";
	output(strr);
	return 0;
}