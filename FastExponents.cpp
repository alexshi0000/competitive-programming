#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		long long x;
		cin >> x;
		if(x % 2 == 0){
			if((x & (x-1)) == 0) cout << "T" << endl;
			else 				 cout << "F" << endl;
		} else cout << "F" << endl;
	}
	return 0;
}
