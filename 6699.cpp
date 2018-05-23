#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c = 0;
	scanf("%d", &a);
	scanf("%d", &b);
	for (int i = a; i <= b; i++) {
		char isRot = 1;
		string in = to_string(i);
		char *num = (char*)in.c_str();
		for (int j = 0; j <= strlen(num) / 2; j++) {
			int first, last;
			first = (int)(num[j] - '0');
			last  = (int)(num[strlen(num)-1-j] - '0');
			if (!(first == 1 && last == 1 ||
				first == 8 && last == 8 ||
					first == 0 && last == 0 ||
						first == 6 && last == 9 ||
							first == 9 && last == 6))
				isRot = 0;
		}
		if (isRot) {
			printf("%d\n", i);
			c++;
		}
	}
	//printf("%d\n", c);
	return 0;
}
