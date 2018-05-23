#include <bits/stdc++.h>
using namespace std;
int main(){
	int items; 
	long w = 0;
	cin >> items;
	for(int i = 0; i < items; i++){
		long c,v;
		cin >> c >> v;
		if(v > 0)
			w += c;
	}
	cout<<w<<endl;
	return 0;
}