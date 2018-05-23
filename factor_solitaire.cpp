#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, cost = 0;
	scanf("%d", &n);
	while (n > 1) {
		int i = (n+1)/2;
		while (i < n && (i % (n-i) != 0))
			i++;
		cost += i/(n-i);
		n = i;
	}
	printf("%d\n", cost);
	return 0;
}