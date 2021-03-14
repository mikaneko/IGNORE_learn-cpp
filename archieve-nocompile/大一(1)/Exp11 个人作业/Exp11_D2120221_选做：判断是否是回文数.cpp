#include <iostream>
using namespace std;

void my_itoa(int n, char s[], int radix) {
	int maxpowernum = 0;
	switch (radix) {
	case 2:maxpowernum = 2147483646; break;
	case 8:maxpowernum = 1073741824; break;
	case 10:maxpowernum = 1000000000; break;
	case 16:maxpowernum = 268435456; break;
	}
	bool doOutput = false;
	int ioutput = 0;
	while (maxpowernum >= 1) {
		if (n / maxpowernum != 0) {
			doOutput = 1;
		}
		if (doOutput == 1) {
			s[ioutput] = (n / maxpowernum) + '0';
			if (n / maxpowernum == 10) { s[ioutput] = 'A'; }
			if (n / maxpowernum == 11) { s[ioutput] = 'B'; }
			if (n / maxpowernum == 12) { s[ioutput] = 'C'; }
			if (n / maxpowernum == 13) { s[ioutput] = 'D'; }
			if (n / maxpowernum == 14) { s[ioutput] = 'E'; }
			if (n / maxpowernum == 15) { s[ioutput] = 'F'; }
			ioutput++;
		}
		//		cout << ioutput << endl;
		n = n % maxpowernum;
		maxpowernum /= radix;
	}

	return;
}

bool isPa(int n,int radix)
{
	char data[100]={0};
	my_itoa(n, data ,radix);
	bool isPalind=true;

	int i = 0;//i为定位变量,将i定位到数组末尾
	while (data[i] != 0) { 
		i++;
	}
	i--;//长度减一


	int left = 0;
	int right = i;
	char temp = 0;
	while (left < right) {
		if(data[left]!=data[right]){
			isPalind=false;
		}
		left++;
		right--;
	}


	if(true==isPalind){return true;}
	else{return false;}
}
int main()
{
	cout<<isPa(123454321,10)<<endl;
	cout<<isPa(123454321,16)<<endl;
	return 0;
}