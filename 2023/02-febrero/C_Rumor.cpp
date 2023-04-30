#include <bits/stdc++.h>

using namespace std;

int n, m, tmp1, tmp2;
long long menor = 0;
vector<int> memo;
vector<vector<int>> graph;
vector<int> values;

int dfs(int pos,int price){
    memo[pos]=1;
    for(int i=0;i<graph[pos].size();i++){
        if(memo[graph[pos][i]]==0){
            price=dfs(graph[pos][i],min(price,values[graph[pos][i]]));
        }
    }
    return price;
}

int main()
{

    cin >> n >> m;

    graph=vector<vector<int>>(n + 10);
    values=vector<int> (n + 10);
    memo=vector<int>(n + 10);

    for (int i = 1; i <= n; i++)
    {
        cin >> values[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (memo[i] == 0)
        {   
            menor+=dfs(i,values[i]);
        }
    }

    cout << menor << endl;

    return 0;
}