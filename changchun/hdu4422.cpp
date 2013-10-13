#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int a[7], n;
int main() {
	int i, j;
	while (~scanf("%d", &n)) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		if (n <= 3) {
			puts("1024");
			continue;
		}
		int ans = 0;
		if (n == 4) {
			do {
				int f = (a[0] + a[1] + a[2]);
				if ( f% 1024 == 0)
					ans = 1024;
				int t = a[2] + a[3];
				if (t > 0 && t % 1024 == 0)
					ans = 1024;
				else
					ans = max(ans, t % 1024);
			} while (next_permutation(a, a + n));
		}
		if (n == 5) {
			do {
				int f = (a[0] + a[1] + a[2]);
				if (f%1024==0 ) {
					int t = a[3] + a[4];
					if (t > 0 && t % 1024 == 0)
						ans = 1024;
					else
						ans = max(ans, t % 1024);
				}
			} while (next_permutation(a, a + n));
		}
		printf("%d\n", ans);
	}
	return 0;
}