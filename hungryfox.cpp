#include <bits/stdc++.h>
using namespace std;

int cmpr(int a, int b) { return a < b;}
//F*CK THIS QUESTION
int main()
{
	int n, w, *arr;
	scanf("%d%d", &n, &w);
	arr  = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr+0,  arr+n,  cmpr);
	long long max_t = 0, min_t = 0x7FFFFFFF;	//max tasty

	//FIRST CASE =========================================
	long long t = abs(w - arr[0]), i = 0, j = n-1;	//j is dest, i is src
	while (i != j) {

		t += max(abs(w-arr[j]), abs(arr[j] - arr[i]));
		//printf("%d %d %lld\n", arr[i], arr[j], t);
		i ^= j;
		j ^= i;
		i ^= j;
		j += j < i;
		j -= j > i;
	}
	max_t = max(max_t, t);

	//SECOND CASE ========================================
	t = abs(w-arr[n-1]), i = n-1, j = 0;
	while (i != j) {
		t += max(abs(w-arr[j]), abs(arr[j] - arr[i]));
		//printf("%d %d %lld\n", arr[i], arr[j], t);
		i ^= j;
		j ^= i;
		i ^= j;
		j += j < i;
		j -= j > i;
	}
	max_t = max(max_t, t);

	long long fwd[n+1];
	long long bck[n+1];
	memset(fwd, 0, sizeof(long long)*(n+1));
	memset(bck, 0, sizeof(long long)*(n+1));
	//THIRD CASE ==========================================
	t = abs(w-arr[0]), i = 0, j = 1;
	while (j < n) {
		t += min(abs(arr[i] - arr[j]), abs(arr[j]-w));
		fwd[j] = fwd[j-1] + min(abs(arr[i] - arr[j]), abs(arr[j]-w));
		i++;
		j++;
	}
	min_t = min(min_t, t);

	//FOURTH CASE ==========================================
	t = abs(w-arr[n-1]), i = n-1, j = n-2;
	while (j >= 0) {
		t += min(abs(arr[i] - arr[j]), abs(arr[j]-w));
		bck[j] = bck[j+1] + min(abs(arr[i] - arr[j]), abs(arr[j]-w));
		i--;
		j--;
	}
	min_t = min(min_t, t);

	//FIFTH CASE ===========================================
	i = 1;
	while (i < n-1) {
		//FIRST SUBCASE
		min_t = min( min_t, abs(arr[i]-w) + fwd[n-1] - fwd[i] + bck[0] - bck[i-1] + min(abs(arr[i-1] - w), abs(arr[i-1] - arr[n-1])));
		//SECOND SUBCASE
		min_t = min( min_t, abs(arr[i]-w) + bck[0] - bck[i] + fwd[n-1] - fwd[i+1] + min(abs(arr[i+1] - arr[0]), abs(arr[i+1] - w)));
		i++;
	}

	printf("%lld %lld\n", min_t, max_t);
	return 0;
}