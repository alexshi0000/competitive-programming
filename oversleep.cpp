#include <bits/stdc++.h>
#define INF (2000000000)
using namespace std;
int **dist, n, m, ro_1, co_1, ro_2, co_2;
bool **visited;
char **arr;
template<typename T>
void print(T ***obj){
	cout<<endl;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j++)
			cout<<(*obj)[i][j]<<" ";
		cout<<endl;
	}
}
bool safe(int ro, int co){
	bool ret = ro < n && ro >= 0 && co < m && co >= 0 && arr[ro][co] != 'X';
	return ret;
}
int main(void) {
	scanf("%d%d",&n,&m);
	arr = (char**)malloc(sizeof(char*)*n);
	dist = (int**)malloc(sizeof(int*)*n);
	visited = (bool**)malloc(sizeof(bool*)*n);
	for(int i = 0; i < n; i++){
		arr[i] = (char*)malloc(sizeof(char)*m);
		dist[i] = (int*)malloc(sizeof(int)*m);
		visited[i] = (bool*)malloc(sizeof(bool)*m);
		memset(visited[i], false, sizeof(bool)*m);
		scanf("%s",arr[i]);
		for(int j = 0; j < m; j++){
			if(arr[i][j] == 's'){
				ro_1 = i;
				co_1 = j;
			}
			else if(arr[i][j] == 'e'){
				ro_2 = i;
				co_2 = j;
			}
		}
	}
	queue<pair<int,int>> q;
	q.push(make_pair(ro_1,co_1));
	dist[ro_1][co_1] = 0;
	bool path_found = 0;
	while(q.size() > 0){
		int ro_f = q.front().first;
		int co_f = q.front().second;
		q.pop();
		visited[ro_f][co_f] = true;
		if(ro_f == ro_2 && co_f == co_2){
			path_found = 1;
			break;
		}
		if(ro_f-1 < n && ro_f-1 >= 0 && co_f < m && co_f >= 0 && arr[ro_f-1][co_f] != 'X'){
			dist[ro_f-1][co_f] = dist[ro_f][co_f] + 1;
			if(!visited[ro_f-1][co_f])
				q.push(make_pair(ro_f-1,co_f));
		}
		if(ro_f < n && ro_f >= 0 && co_f-1 < m && co_f-1 >= 0 && arr[ro_f][co_f-1] != 'X'){
			dist[ro_f][co_f-1] = dist[ro_f][co_f] + 1;
			if(!visited[ro_f][co_f-1])
				q.push(make_pair(ro_f,co_f-1));
		}
		if(ro_f+1 < n && ro_f+1 >= 0 && co_f < m && co_f >= 0 && arr[ro_f+1][co_f] != 'X'){
			dist[ro_f+1][co_f] = dist[ro_f][co_f] + 1;
			if(!visited[ro_f+1][co_f])
				q.push(make_pair(ro_f+1,co_f));
		}
		if(ro_f < n && ro_f >= 0 && co_f+1 < m && co_f+1 >= 0 && arr[ro_f][co_f+1] != 'X'){
			dist[ro_f][co_f+1] = dist[ro_f][co_f] + 1;
			if(!visited[ro_f][co_f+1])
				q.push(make_pair(ro_f,co_f+1));
		}
	}
	if(path_found)
		printf("%d\n",dist[ro_2][co_2]-1);
	else
		printf("%d\n",-1);
	return 0;
}