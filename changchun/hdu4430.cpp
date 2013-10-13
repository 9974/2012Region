#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll n;
ll cal(ll k, ll r, ll s) {
	ll p = 1;
	int i;
	for(i = 1; i <= r; i++) {
		if(p > n/k) return n+1;
		p *= k;
		s += p;
		if(s > n) return n+1;
	}
	return s;
}
ll a, b;
void gao(ll r, ll s) {
	ll L = 2, R = n;
	while(L <= R) {
		ll m = (L + R) >> 1;
		ll v = cal(m, r, s);
		if(v == n) {
			if(a*b > r*m || (a*b == r*m && a > r)) {
				a = r;
				b = m;
			}
			return;
		}
		if(v > n) R = m-1;
		else L = m+1;
	}
}

int main() {
	int i, j;
	while(cin >> n) {
		a = 1; b = n;
		for(i = 1; i <= 38; i++)
			gao(i, 0), gao(i, 1);
		cout << a << " " << b << endl;
	}
	return 0;
}