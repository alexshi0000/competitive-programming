#include <bits/stdc++.h>
using namespace std;

struct functor
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
} cmpr;

int main()
{
	char arr[101];
	int freq[26];
	memset(freq, 0, sizeof(int) * 26);
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++)
		freq[arr[i]-'a']++;
	sort(freq, freq+26, cmpr);
	int removed = 0;
	for (int i = 2; i < 26; i++)
		removed += freq[i];
	printf("%d\n", removed);
	return 0;
}