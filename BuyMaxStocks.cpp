#include <bits/stdc++.h>
using namespace std;

class stock{
	public:
		long long amount, cost;
		stock(unsigned long long cost, unsigned long long amount){
			this->amount = amount;
			this->cost = cost;
		}
};

struct stock_comparator{
	public:
		bool operator()(const stock *a, const stock *b){
			if(a->cost < b->cost)
				return true;
			return false;
		}
};

int main(){
	int n;
	cin >> n;
	vector<stock*> stocks(n);
	for(int i = 0; i < n; i++){
		long long amt;
		cin >> amt;
		stocks[i] = new stock(amt,i+1);
	}
	long long k;
	long long counter = 0;
	cin >> k;
	stock_comparator cmpr;
	sort(stocks.begin(), stocks.end(), cmpr);
	for(int i = 0; i < n; i++){
		if(k/stocks[i]->cost >= stocks[i]->amount){
			k -= stocks[i]->cost * stocks[i]->amount;
			if(k < 0)
				break;
			counter += stocks[i]->amount;
		}
		else{
			long long amt = k/stocks[i]->cost;
			k -= amt*stocks[i]->cost;
			if(k < 0)
				break;
			counter += amt;
		}
	}
	cout << counter << endl;
	return 0;
}