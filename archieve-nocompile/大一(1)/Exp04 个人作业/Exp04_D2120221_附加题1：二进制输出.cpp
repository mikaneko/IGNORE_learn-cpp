#include <iostream>
using namespace std;

//�����������ĳ˷���aΪ������bΪָ����
int MATH_intpower(int a,int b){
	int MATH_temp = 1;
	for (int i=1;i<=b;i+=1){
		MATH_temp = MATH_temp*a;
	}
	return MATH_temp;
}
//��������
int main(){
	while(1){
	
		int n = 0;
		int powertemp = 0;
		int binoout = 0;
		bool haveone = 0;
		cout<<"����������n��ת��Ϊ���������"<<endl;
		cout<<"������n��ֵ:\t";
		cin>>n;
		cout<<"�����������"<<endl;
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

