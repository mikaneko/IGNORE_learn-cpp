#include <iostream>
using namespace std;

int main(){

	double radius=0,area=0,volume=0;
	const double pi=3.14159;
	cout<<"Please input the value of the radius.\n";
	cin>>radius;
	area = 4*pi*radius*radius;
	volume=4.0/3*pi*radius*radius*radius;
	cout<<"==================================="<<endl;
	cout<<"Area=\t"<<area<<endl;
	cout<<"Volume=\t"<<volume<<endl;
	
	system("pause");
	return 0;
}
