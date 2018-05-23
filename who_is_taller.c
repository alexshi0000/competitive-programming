#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define tos to_string
using namespace std;

vector< vector<int> > arr;

int traverse(int start, int end)
{
	if (start == end)
		return 1;
	int found = 0;
	for (int i = 0; i < arr[start].size() && !found; i++)
		found = traverse(arr[start].at(i), end);
	return found;
}

int main()
{
	int n, m, *chdrn;
	scanf("%d%d", &n, &m);
	arr = vector< vector<int> >(n);
	chdrn = (int*)malloc(sizeof(int)*n);
	memset(chdrn, 1, sizeof(int)*n);
	for (int i = 0; i < m; i++) {
		int gr, ls;
		scanf("%d%d", &gr, &ls);
		arr[gr-1].pb(ls-1);
		chdrn[gr-1] += chdrn[ls-1];
	}
	int p1, p2;
	scanf("%d%d", &p1, &p2);
	if (chdrn[p1-1] < chdrn[p2-1]) {
		if (traverse(p1-1, p2-1))
			printf("yes\n");
		else if(traverse(p2-1, p1-1))
			printf("no\n");
		else
			printf("unknown\n");
	}
	else {
		if (traverse(p2-1, p1-1))
			printf("no\n");
		else if(traverse(p1-1, p2-1))
			printf("yes\n");
		else
			printf("unknown\n");
	}
	return 0;
}