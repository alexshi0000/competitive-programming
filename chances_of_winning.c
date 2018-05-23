#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

vector<pair<int,int>> match;

int chance(int sc[4], int t, int g, int s)
{
	if (g == 6)
		return (t == 0 && sc[t] > sc[1] && sc[t] > sc[2] && sc[t] > sc[3]) ||
			(t == 1 && sc[t] > sc[0] && sc[t] > sc[2] && sc[t] > sc[3]) ||
			(t == 2 && sc[t] > sc[1] && sc[t] > sc[0] && sc[t] > sc[3]) ||
			(t == 3 && sc[t] > sc[1] && sc[t] > sc[2] && sc[t] > sc[0]);
	int p = 0, brnch[4];
	memset(brnch, 0, sizeof(brnch));
	for (int i = 0; i < 4; i++)
		brnch[i] = sc[i];

	//cout << match.at(s).first << " " << match.at(s).second << endl;

	brnch[match.at(s).first] += 3;
	p += chance(brnch, t, g+1, s+1);
	brnch[match.at(s).first] -= 3;

	brnch[match.at(s).second] += 3;
	p += chance(brnch, t, g+1, s+1);
	brnch[match.at(s).second] -= 3;

	brnch[match.at(s).first]  += 1;
	brnch[match.at(s).second] += 1;
	p += chance(brnch, t, g+1, s+1);
	brnch[match.at(s).first]  -= 1;
	brnch[match.at(s).second] -= 1;
	return p;
}

int main(int arc, char **argv)
{
	int t, g, score[4], visited[4][4];
	memset(score, 0, sizeof(score));
	memset(visited, 0, sizeof(visited));
	scanf("%d %d", &t, &g);
	for (int i = 0; i < g; i++) {
		int a, b, as, bs;
		scanf("%d %d %d %d", &a, &b, &as, &bs);
		score[a-1] += (int)(as > bs) * 3 + (int)(as == bs);
		score[b-1] += (int)(bs > as) * 3 + (int)(bs == as);
		visited[a-1][b-1] = 1;
		visited[b-1][a-1] = 1;
	}
	if(visited[0][1] == 0 && visited[1][0] == 0)
		match.pb(mp(0,1));
	if(visited[0][2] == 0 && visited[2][0] == 0)
		match.pb(mp(0,2));
	if(visited[0][3] == 0 && visited[3][0] == 0)
		match.pb(mp(0,3));

	if(visited[1][2] == 0 && visited[2][1] == 0)
		match.pb(mp(1,2));
	if(visited[1][3] == 0 && visited[3][1] == 0)
		match.pb(mp(1,3));
	if(visited[2][3] == 0 && visited[3][2] == 0)
		match.pb(mp(2,3));

	printf("%d\n", chance(score, t-1, g, 0));
	return 0;
}