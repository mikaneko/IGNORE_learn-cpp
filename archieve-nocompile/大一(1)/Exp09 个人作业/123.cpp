#include <iostream>
#include <ctime>


using namespace std;

int main(){
	int timeleft=time(0);
	int year = 1970;
	while(1){
		//年的计算
		if((year%4==0&&year%100!=0)||(year%100==0)){
			if(timeleft-60*60*24*366>0){timeleft-=60*60*24*366;}
			else break;
		}
		else{
			if(timeleft-60*60*24*365>0){timeleft-=60*60*24*365;}
			else break;
		}
		year++;
		//cout<<year<<endl;
		//cout<<timeleft<<endl;	
	}

	cout<<year<<"年"<<endl;

		//月的计算
	int dayinmonth[13];
	if((year%4==0&&year%100!=0)||(year%100==0))
	{
		dayinmonth[1]=31;
		dayinmonth[2]=29;
		dayinmonth[3]=31;
		dayinmonth[4]=30;
		dayinmonth[5]=31;
		dayinmonth[6]=30;
		dayinmonth[7]=31;
		dayinmonth[8]=31;
		dayinmonth[9]=30;
		dayinmonth[10]=31;
		dayinmonth[11]=30;
		dayinmonth[12]=31;
	}
		

	else
	{
		dayinmonth[1]=31;
		dayinmonth[2]=28;
		dayinmonth[3]=31;
		dayinmonth[4]=30;
		dayinmonth[5]=31;
		dayinmonth[6]=30;
		dayinmonth[7]=31;
		dayinmonth[8]=31;
		dayinmonth[9]=30;
		dayinmonth[10]=31;
		dayinmonth[11]=30;
		dayinmonth[12]=31;
	}

	int i=0;
	while(i<=11){
		if(timeleft-=dayinmonth[i]*60*60*24>0){timeleft-=dayinmonth[i]*60*60*24;}
		else break;
		i++;
		//cout<<timeleft<<endl;
		//cout<<i<<"月"<<endl;
	}
	cout<<i<<"月"<<endl;


	int dayday=1;
	//计算天
	while(1){
		if(timeleft-=60*60*24>0){timeleft-=60*60*24;}
		else break;
		dayday++;
			cout<<dayday<<"日"<<endl;


	}
	cout<<dayday<<"日"<<endl;

	return 0;
}


