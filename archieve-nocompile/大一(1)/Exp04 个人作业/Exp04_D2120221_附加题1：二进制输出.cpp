#include <iostream>
using namespace std;

//定义正整数的乘方（a为底数，b为指数）
int MATH_intpower(int a,int b){
	int MATH_temp = 1;
	for (int i=1;i<=b;i+=1){
		MATH_temp = MATH_temp*a;
	}
	return MATH_temp;
}
//程序主体
int main(){
	while(1){
	
		int n = 0;
		int powertemp = 0;
		int binoout = 0;
		bool haveone = 0;
		cout<<"输入正整数n，转换为二进制输出"<<endl;
		cout<<"请输入n的值:\t";
		cin>>n;
		cout<<"二进制输出："<<endl;
		for(int i=30;i>=0;i-=1){
			if(n>=(MATH_intpower(2,i))){
				cout<<'1';n-=MATH_intpower(2,i);haveone =1;
			}
			else{
				if(haveone==1){cout<<'0';};
			}
		}
		cout<<endl;
	}
		return 0;
}

