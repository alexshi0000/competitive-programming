#include<bits/stdc++.h>
using namespace std;
int main(){
	int r,c;
	cin >> r >> c;
	bool found_x[c];
	bool found_y[r];
	memset(found_x,0,sizeof(found_x));
	memset(found_y,0,sizeof(found_y));
	for(int i = 0; i < r; i++){
		char s[c];
		scanf("%s",s);
		for(int j = 0; j < c; j++){
			if(s[j] == 'X'){
				found_x[j] = true;
				found_y[i] = true;
			}
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int x, y;
		scanf("%i",&x);
		scanf("%i",&y);
		if(found_x[x-1] || found_y[y-1])
			printf("%s","Y\n");
		else
			printf("%s","N\n");
	}
	return 0;
}