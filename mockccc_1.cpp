#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, cnt = 0;
	scanf("%d %d", &n, &x);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	for (int i = 1; i < n-1; i++) {
		if (arr[i] == x) {
			cnt += (i - 0) * (n - 1 - i);
		}
	}
	printf("%d\n", cnt);
	return 0;
}