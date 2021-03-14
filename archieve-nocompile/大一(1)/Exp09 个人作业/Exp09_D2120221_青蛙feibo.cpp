#include <iostream>
using namespace std;

int cot(int);



int main(){
	for(int i=1;i<=10;i++)
	cout<<cot(i)<<endl;
	return 0;
}



int cot(int a){
	if(a==1)return 1;
	if(a==2)return 2;
	
	return cot(a-1)+cot(a-2);
}