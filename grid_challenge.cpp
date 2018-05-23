#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int t;
	scanf("%d",&t);
	for(int T = 0; T < t; T++){
		int n;
		scanf("%d",&n);
		char arr[n][n];
		for(int i = 0; i < n; i++){
			scanf("%s",arr[i]);
			sort(arr[i]+0, arr[i]+n);
		}
		bool sorted = 1;
		for(int j = 0; j < n && sorted; j++){
			for(int i = 1; i < n; i++){
				if(arr[i][j] < arr[i-1][j]){
					sorted = 0;
					break;
				}
			}
		}
		if(sorted)
			printf("%s\n","YES");
		else
			printf("%s\n","NO");
	}
	return 0;
}