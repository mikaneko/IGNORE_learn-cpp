#include <iostream>
using namespace std;

int main(){
	
	char hometown[] = "银河系地球村";
	char name[] = {(char)0x35,(char)0x25,(char)0x1a,(char)0x03,(char)0x56,(char)0x2e,0};
	
	//guojima
	name[0] +=0x20;
	name[1] +=0x20;
	name[2] +=0x20;
	name[3] +=0x20;
	name[4] +=0x20;
	name[5] +=0x20;

	//机内码
	name[0] +=0x80;
	name[1] +=0x80;
	name[2] +=0x80;
	name[3] +=0x80;
	name[4] +=0x80;
	name[5] +=0x80;

	cout<<"我是来自\""<<hometown<<"\"的\""<<name<<'\"'<<endl;

	system("pause");
	return 0;
}