#include <iostream>
using namespace std;

int main(){

	int a=-3,b=7,temp;
	cout<<"c = "<<a<<'\t'<<"b = "<<b<<endl;
	temp = a;
	a = b;
	b = temp;
	cout<<"c = "<<a<<'\t'<<"b = "<<b<<endl;
		
	system("pause");
	return 0;
}
