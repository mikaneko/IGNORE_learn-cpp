#include <iostream>
using namespace std;

int main(){

	int input;
	cout<<"Which num do u wanna test?\n";
	cin>>input;
	if(input%2)
		cout<<"num"<<input<<'\t'<<"is odd.";
	else
		cout<<"num"<<input<<'\t'<<"is even.";
		
	system("pause");
	return 0;
}