#include <iostream>
using namespace std;

int main(){
	
	int input;
	cout<<"Which num do u wanna test?\n";
	cin>>input;
	if(input&1)
		cout<<"num"<<input<<'\t'<<"is odd.\n";
	else
		cout<<"num"<<input<<'\t'<<"is even.\n";
	
	system("pause");
	return 0;
}