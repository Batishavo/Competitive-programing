#include <bits/stdc++.h>

using namespace std;

int n,
    m;

bool used[110];

vector<int> adj[110], answer;

void topo_sort(int i)
{
    used[i] = 1;
    for (int j : adj[i])
    {
        if (!used[j])
        {
            topo_sort(j);
        }
    }
    answer.push_back(i);
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                topo_sort(i);
            }
        }

        reverse(answer.begin(), answer.end());

        for (int i = 0; i < n; i++)
        {
            cout << answer[i];
            if(i!=n-1){
                cout << " ";
            }
        }
        cout << endl;
        for(int i = 0; i <=n; i++){
            adj[i].clear();
            used[i]=0;
        }
    }

    return 0;
}