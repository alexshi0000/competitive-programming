#include <bits/stdc++.h>
using namespace std;

struct fnctr{
	bool operator()(int a, int b)
	{
		return a >= b;
	}
} cmpr;

int tiles, r, c;
char plan[25][25], visited[25][25];

int search(int x, int y)
{
	if (x < 0 || y < 0 || x >= r || y >= c || plan[x][y] == 'I' || visited[x][y])
		return 0;
	visited[x][y] = 1;
	return 1 + search(x+1, y) + search(x-1, y)
		 + search(x, y+1) + search(x, y-1);
}

int main()
{
	scanf("%d", &tiles);
	scanf("%d", &r);
	scanf("%d", &c);
	for (int i = 0; i < r; i++) {
		char in[c];
		scanf("%s", in);
		for (int j = 0; j < c; j++) {
			plan[i][j] = in[j];
			visited[i][j] = 0;
		}
	}
	vector<int> amounts;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int n = search(i, j);
			if (n > 0)
				amounts.push_back(n);
		}
	}
	//do alg here
	/*for (int i = 0; i < amounts.size(); i++)
		printf("%d\n", amounts.at(i));*/
	int total = 0;//tiles used
	int cnt   = 0;//floors covered
	int leftover = 0;
	sort(amounts.begin(), amounts.end(), cmpr);
	for (int i = 0; i < amounts.size(); i++) {
		if (total + amounts.at(i) > tiles){
			break;
		}
		total += amounts.at(i);
		cnt++;
	}
	if (cnt == 1)
		cout << to_string(cnt) + " room,"<<" "<<tiles-total<<" square metre(s) left over"
	<<endl;
	else
	cout << to_string(cnt) + " rooms,"<<" "<<tiles-total<<" square metre(s) left over"
	<<endl;
	return 0;
}