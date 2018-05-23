#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, h;
	cin >> h;
	cin >> m;
	for (int t = 1; t <= m; t++) {
		int A = -6*pow(t,4) + h*pow(t,3) + 2*pow(t,2) + t; 
		if (A <= 0) {
			cout << "The balloon first touches ground at hour:"<< endl;
			cout << t << endl;
			return 0;
		}
	}
	cout << "The balloon does not touch ground in the given time." << endl;
	return 0;
}