#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int w, n;
	scanf("%d%d", &w, &n);
	int t[n+1];
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		t[i] += t[i-1];
	}
	int r, l;
	r = 1;
	l = 1;
	while (r <= n) {
		if (t[r] - t[l-1] > w)
			break;
		l += (int)(r >= 4);	//only increment l if r >= 4
		r++;
	}
	printf("%d\n",r-1);
	return 0;
}