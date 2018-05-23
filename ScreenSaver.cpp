#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	int *bits = (int*) malloc(sizeof(int)*s.size());
	for(int i = 0; i < s.size(); i++){
		if(s.c_str()[i] == '|')
			bits[i] = 1;
		else
			bits[i] = 0;
	}
	for(int i = 0; i < t; i++){
		int changed = -1;
		int seconds = 0;
		cin>>changed;
		if(bits[changed] == 1)
			bits[changed] = 0;
		else
			bits[changed] = 1;
		//
			
		//
		if(bits[changed] == 1)
			bits[changed] = 0;
		else
			bits[changed] = 1;
	}
	return 0;
}