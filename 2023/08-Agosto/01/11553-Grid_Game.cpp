#include <bits/stdc++.h>

using namespace std;

int grid[10][10];

int memo_i[10];
int memo_j[10];

int main()
{

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int test;
    int n;

    cin >> test;

    while (test--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        
        int answer=0;

        for (int k = 0; k < n; k++)
        {

            int maximo = INT_MAX;
            int pos_i = 0;
            int pos_j = 0;

            for (int i = 0; i < n; i++)
            {
                if (memo_i[i] == 1)
                {
                    continue;
                }

                for (int j=0;j<n;j++){
                    if(memo_j[j] == 1){
                        continue;
                    }
                    if(grid[i][j]<maximo){
                        maximo = grid[i][j];
                        pos_i = i;
                        pos_j = j;

                    }
                }
            }

            answer+=maximo;
            memo_i[pos_i]=1;
            memo_j[pos_j]=1;

        }
        cout<<answer<<endl;
        for(int i=0; i < n; i++){
            memo_i[i]=0;
            memo_j[i]=0;
        }
    }

    return 0;
}