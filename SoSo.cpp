#include <bits/stdc++.h>
using namespace std;

int r = -1, c = -1;

bool solve(char arr[][]){
	bool top =, bottom = false, right = false, left = false, center = false;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(i == 0)
				top = true;
			else if(i == r-1)
				bottom = true;
			else if(j == 0)
				left = true;
			else 
				right = true;
			
		}
	}
}                                      
int main(){
	string results[10];
	for(int T = 0; T < 10; T++){
		cin >> r >> c;
		char board[r*c];
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cin >> board[i*r + j];
			}
		}

	}
	return 0;
}