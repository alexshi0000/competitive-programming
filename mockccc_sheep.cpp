#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	double sx[n];
	double sy[n];
	for (int i = 0; i < n; i++) {
		double  x, y;
		scanf("%lf", &x);
		scanf("%lf", &y);
		sx[i] = x;
		sy[i] = y;
	}

	vector< pair<double, double> > eaten;

	for (double i = 0; i <= 1000; i+=0.001) {
		double min_dist = 1e9;
		for (int j = 0; j < n; j++) {
			double x = sx[j];
			double y = sy[j];
			if (sqrt(pow(y,2) + pow(x-i,2)) < min_dist) {
				min_dist = sqrt(pow(y,2) + pow(x-i,2));
			}
		}
		for (int j = 0; j < n; j++) {
			double x = sx[j];
			double y = sy[j];
			if (abs(sqrt(pow(y,2) + pow(x-i,2)) - min_dist) < 1e-4) {
				bool found = 0;
				for (int i = 0; i < eaten.size() && !found; i++) {
					if (abs(x - eaten.at(i).first) < 1e-4 && abs(y - eaten.at(i).second) < 1e-4)
						found = 1;
				}
				if (!found) {
					eaten.push_back(make_pair(x,y));
					//cout << "wtf" << endl;
				}
			}
		}
	}
	for (int i = 0; i < eaten.size(); i++) {
		double x = eaten.at(i).first;
		double y = eaten.at(i).second;
		printf("The sheep at (%.2f, %.2f) might be eaten.\n", x, y);
	}
	return 0;
}