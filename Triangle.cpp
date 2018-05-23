#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n][n];
	int max[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cin >> arr[i][j];
			max[i][j] = 0;
			if(i == 0){
				max[i][j] = arr[i][j];
				break;
			}
			if(j > 0){
				max[i][j] = std::max(max[i][j], max[i-1][j-1]);
			}
			else{
				max[i][j] = std::max(max[i][j], max[i-1][j]);
			}
			if(j < i){
				max[i][j] = std::max(max[i][j], max[i-1][j]);
			}
			else{
				max[i][j] = std::max(max[i][j], max[i-1][j-1]);
			}
			max[i][j] += arr[i][j];
		}
	}
	int tmax = 0;
	for(int i = 0; i < n; i++)
		if(max[n-1][i] > tmax)
			tmax = max[n-1][i];
	cout << tmax << endl;
	return 0;
}