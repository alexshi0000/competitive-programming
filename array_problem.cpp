#include <bits/stdc++.h>
using namespace std;
/*
int main()
{
	int n, total = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	char m = 1;	//can we modify
	while (m) {
		m = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j && arr[i] > 0 && arr[j] > 0) {
					int sm = min(arr[i], arr[j]);
					cout << sm << endl;
					arr[i] = arr[i] - sm;
					arr[j] = arr[j] - sm;
					for (int k = 0; k < n; k++)
						cout << arr[k] <<" ";
					cout << endl;
					m += sm;
				}
			}
		}
		total += m;
	}
	cout << total << endl;
	return 0;
}*/

struct fnctr{
	bool operator()(int a, int b)
	{
		return a > b;
	}
} cmpr;

void print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i ]<< " ";
	cout << endl;
}

int main()
{
	long n, total = 0;
	cin >> n;
	long arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	return 0;
}