#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	long long n, freq[6], combo = 0;
	memset(freq, 0, sizeof(long long)*6); 
	double score;
	scanf("%lld %lf", &n, &score);
	for (long long i = 0; i < n; i++) {
		long long hit;
		scanf("%lld", &hit);
		hit = abs(hit);
		if (hit <= 50 ) {
			freq[0]++;
			combo++;
			freq[5] = max(freq[5], combo);
		}
		else if (hit <= 100 ) {
			freq[1]++;
			combo++;
			freq[5] = max(freq[5], combo);
		}
		else if (hit <= 150 ) {
			freq[2]++;
			combo++;
			freq[5] = max(freq[5], combo);
		}
		else if (hit <= 200 ) {
			freq[3]++;
			combo++;
			freq[5] = max(freq[5], combo);
		}
		else {
			freq[4]++;
			combo = 0;
		}
	}
	//prlong longf("%d %d %d %d %d %d\n", freq[0], freq[1], freq[2], freq[3], freq[4], freq[5]);
	double new_score = 1.5 * (double)freq[0] + (double)freq[1] + (double)freq[2] + 0.5 * (double)freq[3] - (double)freq[4] + 0.5 * (double)freq[5];
	if (new_score - score <= 0)
		cout << setprecision(1) << fixed << 0.0 << endl;
	else
		cout << setprecision(1) << fixed << (new_score - score) << endl;
	return 0;
}