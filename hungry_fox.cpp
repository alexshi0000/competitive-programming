#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF

struct cmp1{
	int operator()(const long a, const long b)
	{
		return a < b;
	}
} cmp0;

struct cmp2{
	int operator()(const long a, const long b)
	{
		return a > b;
	}
} cmp1;

int main()
{
	long n, w, *t, *r_t;
	scanf("%ld %ld", &n, &w);
	t   = (long*)malloc(sizeof(long)*n);
	r_t = (long*)malloc(sizeof(long)*n);
	for (long i = 0; i < n; i++) {
		scanf("%ld", &t[i]);
		r_t[i] = t[i];
	}
	sort(  t+0,   t+n, cmp0);
	sort(r_t+0, r_t+n, cmp1);
	
	
	return 0;
}