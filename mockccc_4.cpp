#include <bits/stdc++.h>
using namespace std;

//document this pseudocode later
/*
long main()
{
	long n, k;
	cin >> n >> k;
	long arr[k], cnt = 0;
	for (long i = 0; i < k; i++) {
		scanf("%d", &arr[i]);
		arr[i]--;
	}
	for (long i = arr[2]; i < n; i++) {
		long *ptr = upper_bound(arr, arr+k, i)-1;
		long idx = (long)(ptr-arr);
		cout << "idx: " << idx << " " << i << endl;
		cnt += arr[idx-2] + 1; //add one with extras
	}
	cout << cnt << endl;
	return 0;
}*/

int main()
{
	long n, k;
	scanf("%ld %ld", &n, &k);
	long arr[k];
	long long cnt = 0;
	for (long i = 0; i < k; i++) {
		scanf("%ld", &arr[i]);
		arr[i]--;
	}
	for (long i = 2; i < k; i++) {
		long idx = i;
		//cout << "idx: " << idx << " " << i << endl;
		cnt += arr[idx-2] + 1; //add one with extras
		if (i < k-1)
			cnt += (arr[i+1]-arr[i]-1) * (arr[idx-2] + 1); 
		else {
			cnt += (n-arr[k-1]-1) * (arr[idx-2] + 1);
		}
	}
	cout << cnt << endl;
	return 0;
}