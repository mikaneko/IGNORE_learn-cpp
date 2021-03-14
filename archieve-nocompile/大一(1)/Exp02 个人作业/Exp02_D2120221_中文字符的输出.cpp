#include <iostream>
using namespace std;

int main(){

	char area[]="盐城";

	char name[]="\xd5\xc5\xba\xa3\xf6\xce";

	cout<<"我是来自\""<<area<<"\"的\""<<name<<'\"'<<endl;
	
	
	system("pause");
	return 0;
}
