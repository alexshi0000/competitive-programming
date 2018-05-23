#include <bits/stdc++.h>
using namespace std;

int min_diff = 2000000000, target;
int n;
bool *used;

vector<int> p1;
vector<int> p2;

void memo(vector<int> from, vector<int> to, int curr_val){
	if(target - curr_val < 0)
		return;

	p1.clear();
	p1 = vector<int>(from);
	p2.clear();
	p2 = vector<int>(to);

	for(int i = 0; i < from.size(); i++){
		vector<int> newfrom(from);
		newfrom.erase(newfrom.begin()+i);
		vector<int> newto(to);
		newto.push_back(from.at(i));
		memo(newfrom, newto, curr_val+from.at(i));
	}
}

int main(){
	cin>>n;
	vector<int> arr(n);
	vector<int> to;
	used = (bool*)malloc(sizeof(bool)*n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		sum += arr[i];
	}
	target = sum/2;
	memo(arr,to,0);
	for(int i = 0; i < p1.size(); i++)
		cout<<p1.at(i)<<" ";
	cout<<endl;
	for(int i = 0; i < p2.size(); i++)
		cout<<p2.at(i)<<" ";
	cout<<endl;
	return 0;
}