#include <bits/stdc++.h>
using namespace std;
/*
void dp(char *a, char *b, int *s, int *max_len){
	int l_a = 0;
	int l_b = 0;
	int r_a = strlen(a)-1;
	int r_b = strlen(b)-1;
	while(r_a >= 0){
		int len = r_a - l_a + 1;
		short memo[len][len];
		memset(memo,0,sizeof(memo));
		for(int i = 0; i < len; i++){
			int ro = 0, co = i;
			while(co < len && ro < len){
				if(i == 0){
					if(a[l_a+ro] == b[l_b+ro])
						memo[ro][co] = 1;
				}
				else{
					memo[ro][co] = memo[ro][(co-ro)/2+ro] + memo[(co-ro)/2+ro+1][co];
				}
				//check if total characters - matched <= s then update max_matches if you need to
				if(co-ro+1 - (int)memo[ro][co] <= *s)
					*max_len = max(*max_len,co-ro+1);
				ro++;
				co++;
			}
		}
		r_a--;
		l_b++;
		if((r_a - l_b + 1) < *s)
			break;
	}
}*/

void dp(char *a, char *b, int *s, int *max_len){
	int len = strlen(a);
	for(int i = 0; i < len; i++){
		int memo[len-i];
		memset(memo,0,sizeof(memo));
		string arr_s = "";
		for(int j = 0; j < len-i; j++){
			int ptr_a = j, ptr_b = i+j;
			if(j > 0)
				memo[j] = memo[j-1];
			if(a[ptr_a] != b[ptr_b])
				memo[j]++;
			arr_s += to_string(memo[j])+" ";
		}
		cout<<arr_s<<endl;
		int repeat = 0;
		if(a[0] == b[i])
			repeat++;
		for(int j = 0; j < len-i; j++){
			if(j > 0 &&memo[j] == memo[j-1])
				repeat++;
			else
				repeat = 0;
			*max_len = max(*max_len, repeat + *s);
		}
		*max_len = max(*max_len, repeat + *s);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int T = 0; T < t; T++){	
		char *a, *b;
		a = (char*) malloc(sizeof(char)*1500);
		b = (char*) malloc(sizeof(char)*1500);
		int s;	
		//s = max numer of mismatches allowed in substr
		scanf("%d%s%s",&s,a,b);
		int max_len = 0;
		//    a ->
		// <- b 
		dp(a,b,&s,&max_len);
		dp(b,a,&s,&max_len);
		printf("%d\n",max_len);
	}
	return 0;
}