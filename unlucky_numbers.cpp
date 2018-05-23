#include <bits/stdc++.h>
using namespace std;
int k, n, *apartment, *floors;
bool *unlucky;
bool sort_func(int a, int b){
	return a < b;
}
int main(){
	//optimized code (just for fun)
	map<int,int> idx_to;
	map<int,int> idx_from;
	scanf("%d",&k);
	unlucky = (bool*)malloc(sizeof(bool)*(k+1));
	for(int i = 0; i < k; i++){
		int b;
		scanf("%d",&b);
		
	}
	scanf("%d",&n);
	apartment = (int*)malloc(sizeof(int)*n);
	floors = (int*)malloc(sizeof(int)*n);
	memset(floors,0,n);
	for(int i = 0; i < n; i++){
		scanf("%d",&apartment[i]);
		idx_to.insert(make_pair(i,apartment[i]));
	}
	sort(apartment,apartment+n, sort_func);
	sort(unlucky,unlucky+k, sort_func);
	for(int i = 0; i < n; i++)
		idx_from.insert(make_pair(apartment[i],i));
	floors[0] = apartment[0];
	for(int i = 1; i < apartment[0]; i++){
		if(found(&unlucky,i))
			floors[0]--;
	}
	for(int i = 1; i < n; i++){
		floors[i] = floors[i-1] + apartment[i] - apartment[i-1];
		for(int j = apartment[i-1]+1; j < apartment[i]; j++)
			if(found(&unlucky,j))
				floors[i]--;
	}
	for(int i = 0; i < n; i++){
		printf("%d\n",floors[idx_from[idx_to[i]]]);
	}
	return 0;
}