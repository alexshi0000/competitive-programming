#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if (!(n % m)) {
		printf("yes %d\n", n/m);
		return 0;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!(n % (m+i))) {
				printf("no %d\n", i);
				return 0;
			}
		}
		return 0;
	}
	return 0;
}