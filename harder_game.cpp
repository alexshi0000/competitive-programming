#include <bits/stdc++.h>
using namespace std;
int dp(){

}
int main(){
	int n, *arr;
	scanf("%d",&n);
	arr = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		scanf("%d",arr[i]);
	printf("%d\n",dp(arr));
	return 0;
}