#include <bits/stdc++.h>

using namespace std;

const int limit = 110;

int n;
int m;
int t;

vector<int> adj[limit];

vector<bool> visited(limit, false);

struct answser
{

    int num;
    vector<int> used;

    answer()
    {
        num = 0;
        used = {};
    }

    anser(int num, vector<int> used)
    {
        this->num = num;
        this->used = used;
    }
};

answer colored()
{

    int menor = INT_MAX;

    for(int i=1;i<=n;i++){
        if(visited[i]==true){
            continue;
        }
        if(adj.size()<menor){
            menor = ade.size();
        }
    }


}

int main()
{

    cin >> t;

    while (t--)
    {

        cin >> n >> m;

        for (int i = 0; i < m; i++)
        {

            int u;
            int v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << answer() << endl;
    }

    return 0;
}