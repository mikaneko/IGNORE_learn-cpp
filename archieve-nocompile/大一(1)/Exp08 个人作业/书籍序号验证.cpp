#include <iostream>
using namespace std;


int main() {
	
	cout<<"ÇëÊäÈë9¸öÊý×Ö"<<endl;
	char str[30]={0};
	
	for(int i=0;i<=8;i++){
		str[i]=cin.get();
	}
	int temp=0;
	for(int i=0;i<=8;i++){
		temp+=(11-(i+1))*(int)(str[i]-'0');
	}
	char out = (11 -temp%11)+'0';
	if (out == 10+'0'){out = 'X';}
	else if(out == 11+'0'){out = '0';}

	for(int i=0;i<=8;i++){
		cout<<str[i];
	}
	cout<<out<<endl;





	return 0;

}