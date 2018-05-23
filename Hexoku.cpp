#include <bits/stdc++.h>
using namespace std;

char order[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

char safe(int i, int j, char arr[16][16]){
	if(arr[i][j] != '-')
		return '(';
	for(int z = 0; z < 16; z++){
		char c = order[z];
		bool found = true;
		for(int ii = (i / 4) * 4; ii < ((i / 4)+1)*4 ; ii++){
			for(int jj = (j / 4) * 4; jj < ((j / 4)+1)*4 ; jj++){
				if(arr[ii][jj] == c)
					found = false;
			}
		}
		for(int ii = i+1; ii < 16; ii++){
			if(arr[ii][j] == c)
				found = false;
		}
		for(int jj = j+1; jj < 16; jj++){
			if(arr[i][jj] == c)
				found = false;
		}
		for(int ii = i-1; ii >= 0; ii--){
			if(arr[ii][j] == c)
				found = false;
		}
		for(int jj = j-1; jj >= 0; jj--){
			if(arr[i][jj] == c)
				found = false;
		}
		if(found){
			return c;
		}
	}
	return '(';
}

int main(){
	//freopen("/home/lx_user/Documents/programming/in.txt","r",stdin);
	for(int T = 0; T < 10; T++){
		int counter = 0;
		char arr[16][16];
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < 16; j++){
				char c; cin >> c;
				arr[i][j] = 0;
				arr[i][j] = c;
			}
		}
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < 16; j++){
				char result = safe(i,j,arr);
				if(result != '('){
					counter++;
					arr[i][j] = result;
				}
			}
		}
		cout << counter << endl;
		/*
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < 16; j++){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		} debugging tool*/
	}
}