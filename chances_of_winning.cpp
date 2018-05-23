#include <bits/stdc++.h>
using namespace std;

void prnt(int arr[4][4])
{
	printf("\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

int chances(int visited[4][4], int score[4][4], int t, int g)
{
	if (g >= 6) {	//all games are played, determine winner
		int max_sc = 0;
		int winner = -1;
		for (int i = 0; i < 4; i++) {
			int ttl_sc = 0;
			for (int j = 0; j < 4; j++)
				ttl_sc += score[i][j];
			if (ttl_sc > max_sc) {
				max_sc = ttl_sc;
				winner = i;
			}
			else if(ttl_sc == max_sc)
				return 0;
		}
		return winner == t;
	}
	int p = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j && !visited[i][j] && !visited[j][i]) {
				cout<<i+1<<" "<<j+1<<" "<<g<<endl;
				int brnch[4][4], v1[4][4], v2[4][4], v3[4][4];
				for (int k = 0; k < 4; k++) {
					for (int m = 0; m < 4; m++) {
						brnch[k][m] = score[k][m];
						v1[k][m] = visited[k][m];
						v2[k][m] = visited[k][m];
						v3[k][m] = visited[k][m];
					}
				}
				v1[i][j] = 1; v2[i][j] = 1; v3[i][j] = 1; 
				v1[j][i] = 1; v2[j][i] = 1; v3[j][i] = 1;
				brnch[i][j] = 3;
				p += chances(v1, brnch, t, g+1);
				brnch[i][j] = 0;

				brnch[i][j] = 1;
				brnch[j][i] = 1;
				p += chances(v2, brnch, t, g+1);
				brnch[i][j] = 0;
				brnch[j][i] = 0;

				brnch[j][i] = 3;
				p += chances(v3, brnch, t, g+1);
				brnch[j][i] = 0;
				break;
			}
		}
	}
	return p;
}

int main()
{
	int t, g, score[4][4];
	scanf("%d %d", &t, &g);
	memset(score, 0, sizeof(score));
	for (int i = 0; i < g; i++) {
		int a, b, as, bs;
		scanf("%d %d %d %d", &a, &b, &as, &bs);
		score[a-1][b-1] = (int)(as > bs)*3 + (int)(as == bs);
		score[b-1][a-1] = (int)(bs > as)*3 + (int)(as == bs);
	}
	/*
	 * how many possible values does t have
	 * out of those possible values count
	 * how many wins you can get by examining
	 * what other scores the other team as have
	 *
	 */
	printf("%d\n", chances(score, score, t-1, g));
	return 0;
}