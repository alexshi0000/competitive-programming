#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int med_freq[n];
	memset(med_freq, 0, sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		int freq[n];
		memset(freq, 0, sizeof(int) * n);
		for (int j = 0; j < n; j++)
			scanf("%d", &freq[j]);
		sort(freq, freq+n);
		med_freq[i] = freq[n/2];
	}
	sort(med_freq, med_freq+n);
	printf("%d\n", med_freq[n/2]);
	return 0;
 }