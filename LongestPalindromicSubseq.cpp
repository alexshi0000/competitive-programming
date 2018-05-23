#include <bits/stdc++.h>
using namespace std;
map<string,int> memo;
string sub_string(string in, int start, int end){
	return in.substr(start, end-start);
}
int largest_palindromic_subseq(string s){
	int n = s.size();
	int lps = 0;
	if(n <= 1)								//base case
		return max(0,n);
	if(memo.find(s) != memo.end())			//found case in memo
		return memo[s];
	if(s.c_str()[0] == s.c_str()[n-1]){
		lps = 2 + largest_palindromic_subseq(sub_string(s,1,n-1));			//matching, add 2 and find rest
	}
	else{														//no matching first and last char
		lps = max(largest_palindromic_subseq(sub_string(s,0,n-1)), 
				  largest_palindromic_subseq(sub_string(s,1,n)));
	}
	memo.insert(make_pair(s,lps));
	return lps;
}
int main(int argc, char **argv){
	return 0;
}