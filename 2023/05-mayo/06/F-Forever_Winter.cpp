#include <bits/stdc++.h>
using namespace std;

const int limit = 210;

int n, 
    m, 
    t,
    r1,
    r2;

vector<vector<int>>adjacent(limit);

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adjacent[u].push_back(v);
            adjacent[v].push_back(u);          
        }
        for(int i=1;i<=n;i++){
            if(adjacent[i].size()==1){
                int aux =adjacent[i][0];
                r2= adjacent[aux].size();
                /*cout<<"--"<<aux<<endl;
                for(int k=0;k<adjacent[aux].size();k++){
                    cout<<adjacent[aux][k]<<" ";
                }
                cout<<endl;*/
                for(int j=0;j<r2;j++){
                    int tmp = adjacent[aux][j];
                    if(adjacent[tmp].size()!=1){
                        r1=adjacent[tmp].size();
                        /*cout<<tmp<<endl;
                        for(int k=0;k<adjacent[tmp].size();k++){
                            cout<<adjacent[tmp][k]<<" ";
                        }
                        cout<<endl;*/
                        break;
                    }
                }
                break;
            }
        }
        cout<<r1<<" "<<r2-1<<endl;
        for(int i = 1; i <=n; i++){
            adjacent[i].clear();
        }
    
    }

    return 0;
}