#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		unsigned long long int n;
		int a;
		cin>>n;
		cin>>a;
		if(a==0)
			cout<<"Airborne wins."<<'\n';
		else
			cout<<"Pagfloyd wins."<<'\n';
	}
	return 0;
}
