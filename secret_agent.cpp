#include <bits/stdc++.h>
using namespace std;
int main(){
	int x1,x2,x3,y1,y2,y3,d;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	cin >> d;
	if(sqrt(pow((double)x3-(double)x2,2)+pow((double)y3-(double)y2,2)) <= d || sqrt(pow((double)x3-(double)x1,2)+pow((double)y3-(double)y1,2)) <= d)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}