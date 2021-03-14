#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	int max,min;
	cout<<"请输入三个不等整数\n";
	cin>>a>>b>>c;
	
	if(a>b)													//A
		{max = a;min = b;}
	else
		{max = b;min = a;}
	
	if(c>max)												//B
		cout<<c<<'\t'<<max<<'\t'<<min<<'\n';
	else{
		if(c<min)
			cout<<max<<'\t'<<min<<'\t'<<c<<'\n';
		else
			cout<<max<<'\t'<<c<<'\t'<<min<<'\n';
		}
		
	system("pause");
	return 0;
}