/*
�������д����Դ���򣬴���Ҫ�����£�
1. ���д����ж����б�ʶ  // *
2. ���ڴ�������ֱ���޸ģ�������ɾ���д������(ֱ���ڴ������޸ģ��Ѵ���������ע����)��
3. ���˴��� //* ��ʶ�������ಿ�ֲ���������µ���䡣
*/

#include<iostream>
#include<iofstream>      // *
#include<string.h>       // *
#include<cstring>
using namespace std;
class student	
{
	char  id[10];
	string  name;
	char   *address;
	double *score;       //�ɼ��������ʼ��ַ
	int  scoreNumber;    //�ɼ�����
public:
	
	student(char *i=0 ,string n="", double *s=0, int sn=0, char *a=0 );
	~student();
    void show();
};	
				 
student::student(char *i=0 ,string n="", double *s=0, int sn=0, char *a=0 )   // *
{
	cout << "Constructor" <<endl;
	if(i) id=i;                 // *
	else id[0]='\0';
	name=n;    
	if(s) 
    {
    	score=new char[sn];     // *
	    for(int k=0;k<sn;k++) score[k]=s[k];   
	}
    else score=0;
    
    scoreNumber=sn;
    if(a) 
    {	
    	address=new char;           // *
    	strcpy(address,a);   
    }
    else address=0;
}
student::~student()
{
	cout << "Destructor" <<endl;
	delete [] score;                //*
	if(address) delete address;     //*
}

void student::show ()	
{
	cout<<id<<'\t'<<name<<'\t';
	for(int k=0; k<scoreNumber; k++) cout<<score[k]<<'\t';
	cout<<address;                  //*
	cout<<endl;
}

int main()
{
	istream  my("Exp06_student_mark1.txt");  //*   ע���ļ�����·�����޸ģ���""�ڵ��ַ������޸�
    double mark1[6];
    for(int i=0;i<6;i++) my>>mark1[i];
    my.close;                       //*
	student *ps1=student("04010401","��Ӣ��",mark1,6,"���ϴ�ѧ���ߵ�ϵ"); //* 
 	ps1->show(); 
	student s2();                   //*
	s2.show();
	double mark3[10]={99,88,66,77,89,78,56,76,88,96};
	student s3("04006606","������",mark3,10,"�Ͼ���ѧ����ϵ");
	s3.show();
	//*
	return 0;
}
