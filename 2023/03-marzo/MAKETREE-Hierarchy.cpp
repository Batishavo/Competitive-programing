#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN], res;
int n, k, w, a, parent[MAXN];
bool vis[MAXN];

void topo_sort(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) topo_sort(v);
    }
    res.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> w;
        while (w--) {
            cin >> a;
            adj[i].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) topo_sort(i);
    }

    reverse(res.begin(), res.end());

    int cur = 0;
    for (int u : res) {
        parent[u] = cur;
        cur = u;
    }

    for (int i = 1; i <= n; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}
