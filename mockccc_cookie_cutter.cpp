#include <bits/stdc++.h>
using namespace std;

int min_x = 0x7FFFFFFF, max_x = -0x7FFFFFFF;

double get_dist(double x1, double y1, double x2, double y2)
{
	return sqrt((double)pow(x1 - x2, 2) + 
		(double)pow(y1 - y2, 2));
}

void get_center(double *cx, double *cy, int x1, 
	int y1, int x2, int y2, int x3, int y3)
{
	double m, b;
	if (x2 > x1) {
		m = -1.0 / 
		(((double)y2 - (double)y1) / 
		((double)x2 - (double)x1));
	} else {
		m = -1.0 / 
		(((double)y1 - (double)y2) / 
		((double)x1 - (double)x2));
	}
	b = (((double)y1 + (double)y2) / 2.0) / 
		((((double)x1 + (double)x2) / 2.0) * m);
	for (double x = min_x; x <= max_x; x++) {
		double y = m*x + b;
		if (abs(get_dist(x,y,x1,y1) - get_dist(x,y,x2,y2)) < 0.1
		&& abs(get_dist(x,y,x3,y3) - get_dist(x,y,x2,y2)) < 0.1) {
			*cx = x;
			*cy = y;
			break;
		} 
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int x[n];
	int y[n];
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		max_x = max(max_x, x[i]);
		min_x = min(min_x, x[i]);
	}

	double radius = 1e9, cx, cy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			double new_radius = get_dist(x[i], y[i], x[j], y[j]);
			if (i == j || new_radius > radius)
				continue;
			cx = ((double)x[i] + (double)x[j]) / 2.0;
			cy = ((double)y[i] + (double)y[j]) / 2.0;
			printf("cx %f cy %f\n", cx, cy);
			bool enclosed = true;
			for (int k = 0; k < n; k++) {
				if (abs(get_dist(x[k], y[k], cx, cy) - new_radius) > 0.1)
					enclosed = false;
			}
			if (enclosed) {
				cout << new_radius << endl;
				return 0;
			}
			else {
				for (int k = 0; k < n; k++) {
					if (i == j || i == k || j == k)
						continue;
					get_center(cx, cy, x[i], y[i], 
						x[j], y[j], x[k], y[k]);
					double new_radius = get_dist(cx, cy, x[i], y[i]);
					bool enclosed = true;
					for (int l = 0; l < n; l++) {
						if (abs(get_dist(x[l], y[l], cx, cy) - new_radius) > 0.1)
							enclosed = false;
					}
					if (enclosed)
						radius = min(radius, new_radius);
				}
			}
		}
	}
	cout << radius << endl;
}