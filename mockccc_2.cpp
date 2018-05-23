#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, *arr, cnt = 0;
	cin >> n;
	arr = (int*) malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = n-1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			if (arr[j] > arr[j-1]) {
				arr[j] ^= arr[j-1];
				arr[j-1] ^= arr[j];
				arr[j] ^= arr[j-1];
				cnt++;
			}
		}
	}
	cout <<cnt<< endl;
	return 0;
}