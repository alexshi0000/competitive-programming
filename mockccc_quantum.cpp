#include <bits/stdc++.h>
using namespace std;

int n, **mat, **tensor, r_prev, c_prev, r, c;

void print(int **arr, int r, int c)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

int main()
{

	int max_el = -0x7FFFFFFF;
	int min_el = 0x7FFFFFFF;
	int max_row = -0x7FFFFFFF;
	int min_row = 0x7FFFFFFF;
	int max_col = -0x7FFFFFFF;
	int min_col = 0x7FFFFFFF;

	mat    = (int**) malloc(sizeof(int*) * 1024);
	tensor = (int**) malloc(sizeof(int*) * 1024);
	for (int i = 0; i < 1024; i++) {
		mat   [i] = (int*) malloc(sizeof(int) * 1024);
		tensor[i] = (int*) malloc(sizeof(int) * 1024);
	}
	scanf("%d", &n);
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			scanf("%d", &mat[i][j]);
	}
	for (int m = 1; m < n; m++) {
		r_prev = r;
		c_prev = c;
		scanf("%d %d", &r, &c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int num;
				scanf("%d", &num);
				for (int k = 0; k < r_prev; k++) {
					for (int l = 0; l < c_prev; l++)
						tensor[r*k+i][c*l+j] = mat[k][l] * num;
				}
			}
		}
		r = r * r_prev;
		c = c * c_prev;
		for (int i = 0; i < 1024; i++)
			memcpy(mat[i], tensor[i], sizeof(int) * 1024);
	}
	//print(tensor, r, c);
	for (int i = 0; i < r; i++) {
		int total_row = 0;
		for (int j = 0; j < c; j++) {
			total_row += tensor[i][j];
			max_el = max(max_el, tensor[i][j]);
			min_el = min(min_el, tensor[i][j]);
		}
		max_row = max(total_row, max_row);
		min_row = min(total_row, min_row);
	}

	for (int j = 0; j < c; j++) {
		int total_col = 0;
		for (int i = 0; i < r; i++)
			total_col += tensor[i][j];
		max_col = max(total_col, max_col);
		min_col = min(total_col, min_col);
	}
	cout<< max_el <<endl;
	cout<< min_el<<endl;
	cout << max_row <<endl;
	cout << min_row<<endl;
	cout << max_col <<endl;
	cout << min_col<<endl;
	return 0;
}