#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5+10;;

int t, n, paso,aux,dif,mayor,res,
    memo[limit][15],
    comp[15];
string cad;
long long cont;

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> n >> cad;
        for(int i=0;i<=9;i++){
            memo[0][i]=0;
        }
        aux=cad[0]-'0';
        memo[0][aux]=1;
        for(int i=1;i<n;i++){
            aux=cad[i]-'0';
            for(int j=0;j<=9;j++){
                memo[i][j]=memo[i-1][j];
            }
            memo[i][aux]=memo[i-1][aux]+1;
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=9;j++){
        //         cout<<memo[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        paso = min(n, 100);
        cont = n;   
        //cout<<"pasp "<<paso<<endl;     
        for (int i = 2; i <= paso; i++)
        {
            // printf("paso actual %d\n",i);
            // cout<<"---------- "<<endl;
            for (int j = 0; j < n; j ++)
            {
                if (j+i-1>=n)
                {
                    break;
                }
                dif=0;
                mayor=0;
                for(int x=0;x<=9;x++){
                    if(j==0){
                        res=0;
                    }
                    else{
                        res=memo[j-1][x];
                    }
                    comp[x]=memo[j+i-1][x]-res;
                    if(comp[x]>0){
                        dif++;
                    }
                    mayor=max(mayor,comp[x]);
                }
                if(dif>=mayor){
                    cont++;
                }
                //printf("l: %d r: %d dif: %d mayor: %d cont: %d\n",j,j+i-1,dif,mayor,cont);
            }
        }
        
        //cout<<"--";
        cout << cont << endl;
    }

    return 0;
}