#include <iostream>
using namespace std;

int main(){
	//第一次cin（体会空格的影响）
	char a[20];
	int i;
	cout<<"Please input the char string including \"space\"\n";
	cout<<"It's a book.\n";
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9];
	a[10]='\0';
	cout<<"保存的是："<<a<<endl;
	
	//第二次cin.get提取一段带有空格的字符组合
	cout<<"请重新输入一遍：";
	cin.get(a[0]);
	cin.get(a[1]);
	cin.get(a[2]);
	cin.get(a[3]);
	cin.get(a[4]);
	cin.get(a[5]);
	cin.get(a[6]);
	cin.get(a[7]);
	cin.get(a[8]);
	cin.get(a[9]);
	cin.get(a[10]);
	cin.get(a[11]);
	cin.get(a[12]);
	cin.get(a[13]);
	a[14]='\0';
	cout<<a<<endl;
	cout<<"此时a0存放上次输入结束的回车符，a14存放本次输入结束的回车符，各自产生一个换行。\n";

	//第三次cin.getline提取一段带有空格的字符组合
	cout<<"使用cin.getline()吸收0后面的字符：\n此时cin.getline(a,6)\n";
	cin.getline(a,6);
	cout<<a<<endl;

	system("pause");
	return 0;
}
