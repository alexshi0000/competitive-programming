#include <bits/stdc++.h>
using namespace std;

struct comp{
	int R, S, D;
	char* N;
	comp(char *n, int r, int s, int d)
	{
		N = n;
		R = r;
		S = s;
		D = d;
	}
};

struct fnct{
	bool operator()(comp *comp1, comp *comp2)
	{
		if( ( comp1->R * 2 + comp1->S * 3 + comp1->D ) <
		( comp2->R * 2 + comp2->S * 3 + comp2->D ))
			return true;
		if(( comp1->R * 2 + comp1->S * 3 + comp1->D ) ==
		( comp2->R * 2 + comp2->S * 3 + comp2->D )) {
			return strcmp(comp2->N, comp1->N) < 0;
		}
		return false;
	}
} cmpr;

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	comp* arr[n];
	for (int i = 0; i < n; i++) {
		int r, s, d;
		char *na = (char*)malloc(sizeof(char)*1000);
		scanf("%s %d %d %d", na, &r, &s, &d);
		arr[i] = new comp(na, r, s, d);
	}
	sort(arr, arr+n, cmpr);
	cout << arr[n-2]->N << endl;
	cout << arr[n-1]->N << endl;
	return 0;
}