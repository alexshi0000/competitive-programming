#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k, p, x, m = 1;
	cin >> k >> p >> x;
	double past = 1e20;
	while (true) {
		double fm = m * x + (double)(k * p)/(double)m;
		if (fm > past)
			break;
		past = fm;
		m++;
	}
	printf("%.3f\n", past);
	return 0;
}