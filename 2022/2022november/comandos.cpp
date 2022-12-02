#include <bits/stdc++.h>

using namespace std;

int inf=1e9;

int t, n, m, ini, fin, p1, p2,maximo,cont=1,
    dis[105][105], p[105][105];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p[i][j] = i;
            if (i == j)
                continue;
            dis[i][j] = inf;
        }
    }
}
void floid_warshall(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //if(i==j) continue;
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> n >> m;
        init(n);
        for (int i = 0; i < m; i++)
        {
            cin >> p1 >> p2;
            dis[p1][p2]=1;
            dis[p2][p1]=1;
        }
        cin>>ini>>fin;
        floid_warshall(n);
        /*for(int i=0;i<n;i++){
            for(int j= 0; j < n; j++){
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }*/
        maximo=dis[ini][fin];
        for(int i=0;i<n;i++){
            if(i!=ini && i!=fin){
                int aux=dis[ini][i]+dis[i][fin];
                maximo=max(maximo,aux);
            }
        }
        printf("Case %d: %d\n",cont++,maximo);
    }

    return 0;
}