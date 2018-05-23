#include <bits/stdc++.h>
using namespace std;

int main()
{
	while (1) {
		int n;
		scanf("%d", &n);
		if (!n)
			break;
		int arr[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		}
		//identity
		int id = -1;
		for (int i = 0; i < n; i++) { //run through different identities
			char id_found = 1;
			for (int j = 0; j < n; j++)
				if (arr[i][j] != j+1 || arr[j][i] != j+1) {
					id_found = 0;
					break;
				}
			if (id_found) {
				id = i;
				break;
			}
		}
		if (id == -1) {
			printf("no\n");
			continue;
		}
		//check aso
		char aso = 1;
		for (int i = 0; i < n && aso; i++) {
			for (int j = 0; j < n && aso; j++) {
				for (int k = 0; k < n && aso; k++) {
					if (i == k || i == j || j == k)
						continue;
					if (arr[i][arr[j][k]-1] != arr[arr[i][j]-1][k]) {
						aso = 0;/*
						cout << i << " " <<
						 j << " " << k << endl;*/
					}
				}
			}
		}
		if (!aso) {
			printf("no\n");
			continue;
		}
		//check inv
		char inv = 1;
		for (int i = 0; i < n; i++) {
			char found = 0;
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == id+1) {
					found = 1;
					break;
				}
			}
			if (!found) {
				inv = 0;
				break;
			}
		}
		if (!inv) {
			printf("no\n");
			continue;
		}
		printf("yes\n");
	}
	printf("\n");
	return 0;
}