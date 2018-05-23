#include <bits/stdc++.h>
using namespace std;

int main()
{
	int freq[101];
	int val[6];
	memset(freq, 0, sizeof(int)*101);
	for (int i = 0; i < 6; i++) {
		cin >> val[i];
		freq[val[i]]++;
	}
	bool per_square = (int)sqrt(val[0]*val[1] + val[2]*val[3] + val[3]*val[4]) *
	(int)sqrt(val[0]*val[1] + val[2]*val[3] + val[3]*val[4]) ==
	val[0]*val[1] + val[2]*val[3] + val[3]*val[4];
	for (int i = 0; i < 101; i++) {
		if (freq[i] == 3) {
			int sum = 0;
			for (int j = 0; j < 101; j++)
				sum += j != i ? j * freq[j] : 0;
			if (sum == i) {
				cout << "YES" << endl;
				return 0;
			}
		}
		if (freq[i] == 2) {
			int sum = 0;
			for (int j = 0; j < 101; j++)
				sum += j != i ? j * freq[j] : 0;
			if ((sum - i) % 3 == 0 && per_square) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}