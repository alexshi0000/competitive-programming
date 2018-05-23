#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define MAX(a,b) (a > b ? a : b)

int dp(char *s){
	int n = strlen(s);
	int **memo = (int**)malloc(sizeof(int*)*n);
	for(int i = 0; i < n; i++){
		memo[i] = (int*)malloc(sizeof(int)*n);
		for(int j = 0; j < n; j++)
			memo[i][j] = (int)(i == j);
	}
	int pad = 1, i, j;
	while(pad < n){
		i = 0;
		j = pad;
		while(j < n){
			if(j - i == 1){
				if(s[j] == s[i])
					memo[i][j] = 2;
				else
					memo[i][j] = 1;
			}
			else if(s[i] == s[j])
				memo[i][j] = 2 + memo[i+1][j-1];
			else
				memo[i][j] = MAX(memo[i+1][j], memo[i][j-1]);
			j++;
			i++;
		}
		pad++;
	}
	int lps = 0;
    for(i = 1; i < n-1; i++){
        lps = MAX(lps,memo[0][i-1]*memo[i][n-1]);
    }
    return lps;
}

int main(void){
	char *input = (char*)malloc(sizeof(char)*3000);
	scanf("%s",input);
	printf("%d\n",dp(input));
	return 0;
}