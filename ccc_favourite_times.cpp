#include <bits/stdc++.h>
using namespace std;

int main()
{
	int d, cnt = 0;
	scanf("%d", &d);
	
	for (int t = 0; t <= d; t++) {
		int minute = t%60;
		int hour = (t / 60) % 24;
		int h = hour == 0 ? 12 : hour;

		if (h == 12 && minute == 34) {
			printf("%d:%d\n", h, minute);
			cnt++;
		}
		else if (h == 11 && minute == 11) {
			printf("%d:%d\n", h, minute);
			cnt++;
		}
		else {
			if (h - minute/10 == minute/10 - minute%10) {
				printf("%d:%d\n", h, minute);
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}