#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
/*
int64 last;

void func(int64 N)
{
	int64 threshold = N*(N-1)/2;
	int64 K = 1, count = 0;
	while (K < N) {
		int64 L = K+1;
		last = K;
		while (L <= N) {
			count += 1;
			L += 1;
			printf("K: %lld L: %lld C: %lld\n", K, L, count);
			if (2 * count >= threshold)
				return;
		}
		K += 1;
	}
}

int main()
{
	int n;
	cin >> n;
	func(n);
	cout << last << endl;
	return 0;
}*/

int main()
{
	int64 N;
	scanf("%lld", &N);
	int64 threshold = N*(N-1)/2;
	threshold = (threshold+1)/2;
	int a;
		if(N > 1000)
			a = (int)(N/(double)3.5);
		else
			a = N/4;
	while (a < N) {
		int64 sum = (((N-a)+(N-1))*a)/2;
		if(sum > threshold){
			break;
		}
		else if(sum == threshold)
			break;
		a++;
	}
	cout << a << endl;
}

/*
int main()
{
	for (int j = 1; j < 1000; j++) {
		int64 N = j;
		int64 sum = 0;
		//scanf("%lld", &N);
		int64 threshold = N*(N-1)/2;
		threshold = (threshold+1)/2;
		int K = 1;

		for (int64 i = N-1; i >= 0; i--) {
			sum += i;
			if (sum >= threshold)
				break;
			K++;
		}
		cout << j << " " << K << " " << j/K << " " << threshold << endl;
	}
	return 0;
}*/