/*
n=1时	自幂数有：0，1，2，3，4，5，6，7，8，9
n=2时	自幂数有：0个
n=3时	自幂数有：153，370，371，407
n=4时	自幂数有：1634，8208，9474
n=5时	自幂数有：54748，92727，93084
n=6时	自幂数有：548834
n=7时	自幂数有：1741725，4210818，9800817，9926315
n=8时	自幂数有：24678050，24678051，88593477
n=9时	自幂数有：146511208，472335975，534494836，912985153
n=10时	自幂数有：0个
*/
#include<iostream>
using namespace std;
int main(){
	int i=1,j=0,k=0;
	cout<<"水仙花数有："<<endl;
	for(;i<=9;i++){
		for(;j<=9;j++){
			for(;k<=9;k++){
			if ((i*100+j*10+k)==(i*i*i+j*j*j+k*k*k)) cout<<i<<j<<k<<endl;
			}
			k=0;
		}
		j=0;
	}
	cout<<"拓展：输入任一不大于10的正整数，下面显示相应位数的自幂数"<<endl;
	cout<<"请输入位数："<<endl;
	int n,start=1,limit,startweishu=1,fenjie;
	int a[10],shuzhi,qiuhe,mi,b=1;
	int panduan=0;
	cin>>n;
	cout<<"自幂数有："<<endl;
	for(;startweishu<n;startweishu++){
		start*=10;
	}
	limit=start*10;
	if(start==1) start=0;
	for(;start<limit;){
		shuzhi=start;
		qiuhe=0;
		for(fenjie=0;fenjie<n;){
			a[fenjie]=shuzhi%10;
			shuzhi/=10;
			fenjie++;
		}
		for(fenjie=0;fenjie<n;){
			for(mi=1;mi<=n;mi++){
				b*=a[fenjie];
			}
			qiuhe+=b;
			b=1;
			fenjie++;
		}	
		if(start==qiuhe) {
			cout<<start<<endl;
			panduan=1;
		}
		start++;
	}
	if(panduan!=1) cout<<"0个"<<endl;
	return 0;
}