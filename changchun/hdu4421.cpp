#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 506 << 1;
int n, b[505][505];
struct twoSat {
    vector<int> edge[maxn];
    int col[maxn];
    int st[maxn], top, opp[maxn];
    void init() {
        for (int i = 0; i < n; i++) {
            opp[i] = i + n;
            opp[i + n] = i;
        }
    }
    void edgeInit() {
        for (int i = 0; i <= 2 * n; i++)
            edge[i].clear();

    }
    bool dfs(int u) {
        if (col[u] == 2)
            return 0;
        if (col[u] == 1)
            return 1;
        col[u] = 1;
        col[opp[u]] = 2;
        st[top++] = u;
        for (int i = 0; i < edge[u].size(); i++)
            if (!dfs(edge[u][i]))
                return 0;
        return 1;
    }
    bool judge() {
        memset(col, 0, sizeof(col));
        for (int i = 0; i < n; i++)
            if (!col[i]) {
                top = 0;
                if (!dfs(i)) {
                    for (int j = 0; j < top; j++)
                        col[st[j]] = col[opp[st[j]]] = 0;
                    if (!dfs(opp[i]))
                        return 0;
                }
            }
        return 1;
    }
    void build(int k) {
        edgeInit();
        int i, j;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (i % 2 == 1 && j % 2 == 1) {
                    if (b[i][j] >> k & 1) {
                        edge[i].push_back(opp[j]);
                    } else {
                        edge[opp[i]].push_back(i);
                        edge[i].push_back(j);
                    }
                } else if (i % 2 == 0 && j % 2 == 0) {
                    if (b[i][j] >> k & 1) {
                        edge[i].push_back(opp[i]);
                        edge[opp[i]].push_back(opp[j]);
                    } else {
                        edge[opp[i]].push_back(j);
                    }
                } else {
                    if (b[i][j] >> k & 1) {
                        edge[i].push_back(opp[j]);
                        edge[opp[i]].push_back(j);
                    } else {
                        edge[opp[i]].push_back(opp[j]);
                        edge[i].push_back(j);
                    }
                }
            }
    }
} g;


int main() {
    int i, j, k;
    while (~scanf("%d", &n)) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
               scanf("%d", &b[i][j]);
        g.init();
        bool ok = 1;
        for (k = 0; k < 32; k++) {
            g.build(k);
            ok &= g.judge();
            if (!ok)
                break;
        }
        if (ok)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}