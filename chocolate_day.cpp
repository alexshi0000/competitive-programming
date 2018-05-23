#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	int n, t, L;
	scanf("%d %d", &n, &t);
	long long d[n + 1], arr[n];
	memset(d, 0, sizeof(long long) * n);
	memset(arr, 0, sizeof(long long) * n);
	for (int i = 0; i < t; i++) {
		int a, b, c;
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		a--;
		b--;
		d[a] += c;
		if (b < n-1)
			d[b+1] -= c;
	}
	arr[0] = d[0];
	long long sum[n]; //cnt is number of cups, curr is the amount of right now
	memset(sum, 0, sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		if (i > 0)
			arr[i] = (d[i] + arr[i-1]);
		if (i == 0)
			sum[i] = arr[i];
		else
			sum[i] = arr[i] + sum[i-1];
	}
	scanf("%d", &L);
	//print_arr(d, n);
	//print_arr(arr, n);
	//print_arr(sum, n);
	long long max_len = 0, l = 0, r = 0;
	while (r < n) {
		while (l < n && ((l > 0 && sum[r] - sum[l-1] > L) || (l == 0 && sum[r] > L))) {
			l++;
			if (l > r)
				r = l;
		}
		if (l >= n)
			break;
		long long amt;
		if (l > 0)
			amt = sum[r] - sum[l-1];
		else
			amt = sum[r];

		if (amt <= L) { 
			//cout << amt << endl;
			max_len = max(max_len, r - l + 1);
		}
		//cout << l << " " << r << endl;
		r++;
	}
	printf("%lld\n", max_len);
	return 0;
}