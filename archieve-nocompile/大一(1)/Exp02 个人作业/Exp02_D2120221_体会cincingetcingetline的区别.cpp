#include <iostream>
using namespace std;

int main(){
	//��һ��cin�����ո��Ӱ�죩
	char a[20];
	int i;
	cout<<"Please input the char string including \"space\"\n";
	cout<<"It's a book.\n";
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9];
	a[10]='\0';
	cout<<"������ǣ�"<<a<<endl;
	
	//�ڶ���cin.get��ȡһ�δ��пո���ַ����
	cout<<"����������һ�飺";
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
	cout<<"��ʱa0����ϴ���������Ļس�����a14��ű�����������Ļس��������Բ���һ�����С�\n";

	//������cin.getline��ȡһ�δ��пո���ַ����
	cout<<"ʹ��cin.getline()����0������ַ���\n��ʱcin.getline(a,6)\n";
	cin.getline(a,6);
	cout<<a<<endl;

	system("pause");
	return 0;
}
