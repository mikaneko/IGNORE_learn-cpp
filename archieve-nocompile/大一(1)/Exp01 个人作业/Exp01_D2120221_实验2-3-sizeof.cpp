#include <iostream>
using namespace std;

int main(){
	int size[6];
	cout<<"sizeof(char)="<<sizeof(char)<<"Byte"<<endl;
	cout<<"sizeof(short)="<<sizeof(short)<<"Byte"<<endl;
	cout<<"sizeof(int)="<<sizeof(int)<<"Byte"<<endl;
	cout<<"sizeof(long)="<<sizeof(long)<<"Byte"<<endl;
	cout<<"sizeof(float)="<<sizeof(float)<<"Byte"<<endl;
	cout<<"sizeof(double)="<<sizeof(double)<<"Byte"<<endl;
	cout<<"char\t"<<sizeof(char)<<endl;
	cout<<"short\t"<<sizeof(short)<<endl;
	cout<<"int\t"<<sizeof(int)<<endl;
	cout<<"long\t"<<sizeof(long)<<endl;
	cout<<"float\t"<<sizeof(float)<<endl;
	cout<<"double\t"<<sizeof(double)<<endl;
	size[0] = sizeof(char);
	size[1] = sizeof(short);
	size[2] = sizeof(int);
	size[3] = sizeof(long);
	size[4] = sizeof(float);
	size[5] = sizeof(double);
	cout<<"char\t"<<size[0]<<endl;
	cout<<"short\t"<<size[1]<<endl;
	cout<<"int\t"<<size[2]<<endl;
	cout<<"long\t"<<size[3]<<endl;
	cout<<"float\t"<<size[4]<<endl;
	cout<<"double\t"<<size[5]<<endl;

	system("pause");
	return 0;
}
