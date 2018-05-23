#include<bits/stdc++.h>
using namespace std;
int max_ef,n,m;
int **heat_map;
void fill(int x, int y, int w){
	int pad = 0;
	for(int i = y-w+1; i < y+w; i++){			//vertical
		int p = 0;
		for(int j = x-w+1; j < x+w; j++){
			if(i >= 0 && i < n && j >= 0 && j < n){
				heat_map[i][j] = heat_map[i][j]+p+1;
				max_ef = max(max_ef,heat_map[i][j]);
			}
			if(j < x && p < pad)
				p++;
			else if(j >= x+w-1-pad && p > 0)
				p--;
		}
		if(i < y)
			pad++;
		else
			pad--;
	}
}
int main(){
	max_ef = -1;
	cin >> n;
	cin >> m;	
	heat_map = (int**) malloc(sizeof(int*)*n);
	for(int i = 0; i < n; i++){
		heat_map[i] = (int*) malloc(sizeof(int)*n);
		fill(heat_map[i],heat_map[i]+n,0);
	}
	for(int i = 0; i < m; i++){
		int x,y,w;
		cin >> y >> x >> w;
		fill(x,y,w);
	}
	cout << max_ef << endl;/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << heat_map[i][j] <<" ";
		cout << endl;
	}*/
	return 0;
}