#include <iostream>
using namespace std;

int main(){
	int a=-3,b=7;
	cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
	a = a^b;
	b = a^b;
	a = a^b;
	cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
		
	system("pause");
	return 0;
}
