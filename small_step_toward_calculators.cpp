#include<bits/stdc++.h>
using namespace std;
int main(){/*
	string s;
	cin >> s;
	char *c = (char*) malloc(sizeof(char)*s.size());
	strcpy(c,s.c_str());
	for(int i = 0; i < s.size(); i++){
		if(c[i] == '-'){
			int a = stoi(s.substr(0,i));
			int b = stoi(s.substr(i+1));
			cout << (a-b) << endl;
			break;
		}
		else if(c[i] == '+'){
			int a = stoi(s.substr(0,i));
			int b = stoi(s.substr(i+1));
			cout << (a+b) << endl;
			break;
		}
	} do this instead*/
	string s;
	cin >> s;
	int idx = s.find("-");
	if(idx == -1){
		idx = s.find("+");
		cout << (stoi(s.substr(0,idx))+stoi(s.substr(idx+1))) << endl;
	}
	else
		cout << (stoi(s.substr(0,idx))-stoi(s.substr(idx+1))) << endl;
	return 0;
}