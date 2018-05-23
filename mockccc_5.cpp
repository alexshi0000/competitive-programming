#include <bits/stdc++.h>
using namespace std;

char mem[500];
int n;
char *arr = (char*) malloc(sizeof(char)*n*n);
int points(int i, int j, char *visited, char curr)
{
	if (i >= n || j >= n || i < 0 || j < 0 || visited[i*n+j])
		return 0;
	//follow the trail
	if (arr[i*n+j] == curr) {
		if (curr == 'I') {
			char *new_visited = (char*) malloc(sizeof(char)*n*n);
			memcpy(new_visited, visited, sizeof(char)*n*n);
			new_visited[i*n+j] = 1; //mark visited
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (new_visited[i*n+j])
						cout << 1;
					else
						cout << 0;
				}
				cout << endl;
			}
			cout << endl;
			return 1 + points(0, 0, new_visited, 'C');
		}
		else {
			char *new_visited = (char*) malloc(sizeof(char)*n*n);
			memcpy(new_visited, visited, sizeof(char)*n*n);
			new_visited[i*n+j] = 1; //mark visited
			int ret = 0;
			
			ret = max(ret, points(i+1, j+1, new_visited, mem[(int)curr]));
			ret = max(ret, points(i-1, j+1, new_visited, mem[(int)curr]));
			ret = max(ret, points(i+1, j-1, new_visited, mem[(int)curr]));
			ret = max(ret, points(i-1, j-1, new_visited, mem[(int)curr]));

			ret = max(ret, points(i+1, j+1, new_visited, mem[(int)curr]));
			ret = max(ret, points(i-1, j+1, new_visited, mem[(int)curr]));
			ret = max(ret, points(i+1, j-1, new_visited, mem[(int)curr]));
			ret = max(ret, points(i-1, j-1, new_visited, mem[(int)curr]));
			return ret;
		}
	}
}

int main()
{
	mem[(int)'C'] = 'A';
	mem[(int)'A'] = 'L';
	mem[(int)'L'] = 'I';
	scanf("%d", &n);
	char *visited = (char*) malloc(sizeof(char) * n * n);
	memset(visited, 0, sizeof(char) * n * n);
	for (int i = 0; i < n; i++) {
		char str[n];
		scanf("%s", str);
		for (int j = 0; j < n; j++)
			arr[i*n + j] = str[j];
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			ret = max(ret, points(i, j, visited, 'C'));
	}
	printf("%d\n", ret);
	return 0;
}