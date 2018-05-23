#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll a = 0;
	ll min_sum = 0;
	ll max_sum = 0;
	ll whole = 0;
	bool error = false;
	for(int i = 0; i < n; i++){
		whole++;
		int k;
		cin >> k;
		if(whole % 2 == 0){
			min_sum += k;
			max_sum += k+1;
		}
		else{
			min_sum += k-1;
			max_sum += k;
		}
		if(k%2!=0)
			error = !error;
	}
	if(min_sum % 2 != 0){
		if(whole % 2 != 0){
			if(error){
				cout << min_sum+1 << endl; 
			}
			else{
				cout << min_sum+1 << endl;
			}
		}
		else{
			if(error){
				cout << min_sum << endl;
			}
			else{
				cout << min_sum << endl;
			}
		}
	}
	else{
		if(whole % 2 != 0){
			if(error){
				cout << min_sum+1 << endl;
			}
			else{
				cout << min_sum << endl;
			}
		}
		else{
			if(error){
				cout << min_sum << endl;
			}
			else{
				cout << min_sum << endl;
			}
		}
	}

	if(max_sum % 2 != 0){
		if(whole % 2 != 0){
			if(error){
				cout << max_sum << endl;
			}
			else{
				cout << max_sum+1 << endl;
			}
		}
		else{
			if(error){
				cout << max_sum << endl;
			}
			else{
				cout << max_sum << endl;
			}
		}
	}
	else{
		if(whole % 2 != 0){
			if(error){
				cout << max_sum-1 << endl;
			}
			else{
				cout << max_sum << endl;
			}
		}
		else{
			if(error){
				cout << max_sum << endl;
			}
			else{
				cout << max_sum << endl;
			}
		}
	}
}