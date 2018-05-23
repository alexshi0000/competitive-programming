#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define INF (0x7FFFFFFF)
/*   BY COMBINATION
int main(void) {
	int t;
	scanf("%d",&t);
	for(int T = 0; T < t; T++){
		int n;
		scanf("%d",&n);
		int *arr = (int*)malloc(sizeof(int)*n);
		for(int i = 0; i < n; i++)
			scanf("%d",&arr[i]);
		int combination = 1;
		int xor_total = -1;
		while(combination <= (INF>>(31-n))){
			int xor_sub = -1;
			printf("%s%d\n","combo: ",combination);
			for(int i = 0; i < n; i++){
				printf("%s%d\n","set bit: ",(combination>>i)%2);
				if((combination>>i) % 2 == 1){
					if(xor_sub == -1)
						xor_sub = arr[i];
					else
						xor_sub = xor_sub ^ arr[i];
				}
			}
			printf("%s%d\n","xor_sub: ",xor_sub);
			if(xor_total == -1)
				xor_total = xor_sub;
			else
				xor_total = xor_total ^ xor_sub;
			combination++;
		}
		printf("%d\n",xor_total);
	}
}*/
int main(void) {
	int t;
	scanf("%d",&t);
	for(int T = 0; T < t; T++){
		int n;
		scanf("%d",&n);
		int *arr = (int*) malloc(sizeof(int)*n);
		for(int i = 0; i < n; i++)
			scanf("%d",&arr[i]);
		int xor_total = 0;
		if(n % 2 != 0){
			xor_total = arr[0];
			for(int i = 2; i < n; i+=2)
				xor_total = xor_total ^ arr[i]; 
		}
		printf("%d\n",xor_total);
	}
}