#include <iostream>
using namespace std;
#define _RADIX_ 10

int my_atoi(char const *data)//只读不写,可用于字符串常量
{
	int outnum=0;
	
	int i = 0;//i为定位变量,将i定位到数组末尾
	while (data[i] != 0) { 
		i++;
	}
	i--;

	int startRadix=1;

	while(i>=0)
	{
		outnum+=startRadix*(data[i]-'0');

		startRadix*=_RADIX_;
		i--;
	}
	return outnum;


}
int main()
{
	char str[]="12345678";
	cout<<my_atoi("654321")<<endl;
	cout<<my_atoi(str)<<endl;
	
	return 0;
}