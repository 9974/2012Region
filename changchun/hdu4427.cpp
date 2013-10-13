#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n, m, k;
int a[44], w;
int dp[2][1003][1003];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int LCM(int a, int b) {
	return a / gcd(a, b) * b;
}
int lcm[1003][1003], idx[1003];
int main() {
	int i, j;
	for(i = 1; i <= 1000; i++)
		for(j = i; j <= 1000; j++)
			lcm[i][j] = lcm[j][i] = LCM(i, j);
	while (~scanf("%d%d%d", &n, &m, &k)) {
		w = 0;
		int t = (int) sqrt(m + 0.5);
		for (i = 1; i <= t; i++) {
			if (m % i == 0) {
				a[w++] = i;
				if (m / i != i)
					a[w++] = m / i;
			}
		}
		sort(a, a+w);
		for(i = 0; i < w; i++)
			idx[a[i]] = i;
		for (i = 0; i <= n; i++)
			for (j = 0; j < w; j++)
				dp[0][i][j] = dp[1][i][j] = 0;
		for (i = 0; i < w; i++)
			dp[0][a[i]][i] = 1;
		int pre = 0, now = 1;
		for (int u = 2; u <= k; u++) {
			for (i = 0; i <= n; i++)
				for (j = 0; j < w; j++)
					dp[now][i][j] = 0;
			for (i = 0; i < n; i++)
				for (j = 0; j < w; j++)
					if (dp[pre][i][j]) {
						for (int x = 0; x < w && i+a[x] <= n; x++) {
								int u = i + a[x];
								int v = idx[lcm[a[x]][a[j]]];
								dp[now][u][v] += dp[pre][i][j];
								if(dp[now][u][v] >= mod) dp[now][u][v] -= mod;

						}
					}
			pre ^= 1, now ^= 1;
		}
		cout << dp[pre][n][w-1] << endl;
	}
	return 0;
}