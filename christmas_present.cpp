#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv){
	int n, min_int = 2000000000;
	cin>>n;
	for(int i = 0; i < n; i++){
		int num;
		cin>>num;
		min_int = min(min_int, num);
	}
	cout<<min_int<<endl;
	return 0;
}