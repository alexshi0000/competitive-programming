#include<bits/stdc++.h>
using namespace std;
/*int main(){
	int n, m;
	scanf("%d",&n);
	scanf("%d",&m);
	long long pre_sum[n];
	long long counter = 0;
	for(int i = 0 ; i < n; i++){
		cin>>pre_sum[i];
		if(i != 0)
			pre_sum[i] += pre_sum[i-1];
		if(pre_sum[i] % m == 0)
			counter++;
		for(int j = 0; j < i; j++){
			if((pre_sum[i]-pre_sum[j])%m == 0)
				counter++;
		}
	}
	cout<<counter<<endl;
}*/
typedef long long ll;

int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	ll pre_sum[n];
	ll counter = 0;
	map<ll,ll> freq;
	for(int i = 0; i < n; i++){
		scanf("%lld",&pre_sum[i]);
		if(i != 0)
			pre_sum[i] += pre_sum[i-1];
		if(pre_sum[i] % m == 0)
			counter++;
		counter += freq[pre_sum[i]%m];
		freq[pre_sum[i]%m]++;
	}
	cout<<counter<<endl;
	return 0;
}