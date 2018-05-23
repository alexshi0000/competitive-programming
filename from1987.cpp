#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = n+1; i < 10400; i++) {
		char str[6], f[10];
		sprintf(str, "%d", i);
		memset(f, 0, sizeof(f));
		for (int j = 0; j < (int)strlen(str); j++) {
			if (str[j] != '\0')
				f[str[j]-'0']++;
		}
		int distinct = 0;
		for (int j = 0; j < 10; j++)
			distinct |= f[j] > 1;
		if (!distinct) {
			printf("%s\n", str);
			break;
		}
	}
}