#include<bits/stdc++.h>
using namespace std;
int **steps;
int n, ro, co;
string s;
bool safe(int ro, int co){
	return ro < n && ro >= 0 && co < n && co >= 0 && steps[ro][co] == -1;
}
void move(int ro, int co, int step){
	if(safe(ro,co)){
		steps[ro][co] = step;
		if(s.compare("e") == 0){
			move(ro,co+1,step+1);
			move(ro-1,co,step+1);
			move(ro+1,co,step+1);
			move(ro,co-1,step+1);
		}
		else if(s.compare("w") == 0){
			move(ro,co-1,step+1);
			move(ro-1,co,step+1);
			move(ro+1,co,step+1);
			move(ro,co+1,step+1);
		}
		else if(s.compare("n") == 0){
			move(ro-1,co,step+1);
			move(ro,co+1,step+1);
			move(ro,co-1,step+1);
			move(ro+1,co,step+1);
		}
		else{
			move(ro+1,co,step+1);
			move(ro,co+1,step+1);
			move(ro,co-1,step+1);
			move(ro-1,co,step+1);
		}
	}
	return;
}
void print(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout<<steps[i][j]<<" ";
		cout<<endl;
	}
}
int main(){
	cin >> n;
	cin >> s;
	cin >> ro >> co;
	steps = (int**) malloc(sizeof(int*)*n);
	for(int i = 0; i < n; i++){
		steps[i] = (int*) malloc(sizeof(int)*n);
		fill(steps[i],steps[i]+n,-1);
	}
	move(ro,co,1);
	print();
	return 0; 
}