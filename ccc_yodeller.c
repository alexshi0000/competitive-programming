#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int final_score[n]; //keep track of scores
	int worst[n];
	memset(worst, 0, sizeof(int)*n);
	memset(final_score, 0, sizeof(int)*n);
	for (int i = 0; i < k; i++) {
		int score[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &score[j]);
			final_score[j] += score[j];
		}
		for (int j = 0; j < n; j++) {
			int ahead = 1;
			for (int l = 0; l < n; l++) {
				if (j == l)
					continue;
				if (final_score[l] > final_score[j])
					ahead++;
			}
			worst[j] = max(worst[j], ahead);
		}
	}
	int best_final = -0x7FFFFFFF;
	for (int i = 0; i < n; i++)
		best_final = max(best_final, final_score[i]);
	for (int i = 0; i < n; i++) {
		if (final_score[i] == best_final) {
			printf("Yodeller %d is the TopYodeller: score %d, worst rank %d\n",
				(i+1), final_score[i], worst[i]);
		}
	}
	return 0;
}