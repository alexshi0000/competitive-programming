#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main(){
	char s[100001];
	scanf("%s",s);
	long len = strlen(s);
	long *l = (long*)malloc(sizeof(long)*len);
	long r = 0;
	int i = len-1;
	while(i >= 0){
		if(i == len-1){
			if(s[i] == ')')
				l[i] = 1;
			else
				l[i] = 0;
		}
		else if(s[i] == ')')
			l[i] = l[i+1] + 1;
		else
			l[i] = l[i+1];
		i--;
	}
	long pair = 0;
	long curr = l[0];
	i = 0;
	while(i < len){
		curr = MIN(l[i],curr);
		if(s[i] == '('){
			if(curr > 0)
				pair++;
			curr--;
			r++;
		}
		i++;
	} 
	if(pair == len/2 || (pair == len/2-1 && r != l[0]))
		printf("%s\n","YES");
	else
		printf("%s\n","NO");
	return 0;
}