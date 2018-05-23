#include <bits/stdc++.h>
using namespace std;
int main(){
	string s, ret;
	cin >> s;
	int k;
	cin >> k;
	int *map = (int*) malloc(sizeof(int)*CHAR_MAX);
	fill(map,map+CHAR_MAX,0);
	for(int i = 0; i < s.size(); i++){
		char c = s.at(i);
		map[(int)c]++;
	}
	for(int i = 0; i < s.size(); i++){
		char c = s.at(i);
		if(map[(int)c] >= k)
			ret += c;
	}
	cout << ret << endl;
	free(map);
	return 0;
}