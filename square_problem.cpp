#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, prev_row = -1, prev_col = -1;
	scanf("%d", &n);
	bool reduced = true, latin = true;
	char arr[n][n] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
		for (int j = 0; j < n; j++) {
			int num = (int)(arr[i][j]-'0');
			if ((j == 0 && num < prev_col) || (i == 0 && num < prev_row))
				reduced = false;
			else if (j == 0)
				prev_col = num;
			else if(i == 0)
				prev_row = num;
		}
	}
	for (int i = 0; i < n; i++) {
		int memo[255];
		memset(memo, 0, sizeof(int)*255);
		for (int j = 0; j < n; j++) {
			int num = (int)(arr[i][j]-'0');
			memo[num]++;
		}
		for (int j = 0; j < n; j++)
			if (memo[(int)(arr[i][j]-'0')] != 1)
				latin = false;
	}
	for (int i = 0; i < n; i++) {
		int memo[255];
		memset(memo, 0, sizeof(int)*255);
		for (int j = 0; j < n; j++) {
			int num = (int)(arr[j][i]-'0');
			memo[num]++;
		}
		for (int j = 0; j < n; j++)
			if (memo[(int)(arr[j][i]-'0')] != 1)
				latin = false;
	}
	if (reduced && latin)
		printf("Reduced\n");
	else if (latin)
		printf("Latin\n");
	else
		printf("No\n");
	return 0;
}