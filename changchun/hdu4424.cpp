#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200003;
typedef long long ll;
struct Edge {
	int a, b, w;
	bool operator<(const Edge &t) const{
		return w > t.w;
	}
	void in() {
		scanf("%d%d%d", &a, &b, &w);
	}
}edge[maxn];
int n;
int fa[maxn], cnt[maxn];
ll sum[maxn];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
	int i, j;
	while(~scanf("%d", &n)) {
		for(i = 0; i < n-1; i++)
			edge[i].in();
		sort(edge, edge+n-1);
		for(i = 1; i <= n; i++) {
			fa[i] = i;
			cnt[i] = 1;
			sum[i] = 0;
		}
		for(i = 0; i < n-1; i++) {
			int ra = find(edge[i].a);
			int rb = find(edge[i].b);
			ll vb = sum[rb]+(ll)edge[i].w*cnt[ra];
			ll va = sum[ra]+(ll)edge[i].w*cnt[rb];
			if(va > vb) {
				fa[rb] = ra;
				cnt[ra] += cnt[rb];
				sum[ra] = va;
			}
			else {
				fa[ra] = rb;
				cnt[rb] += cnt[ra];
				sum[rb] = vb;
			}
		}
		printf("%I64d\n", sum[find(1)]);
	}
	return 0;
}
