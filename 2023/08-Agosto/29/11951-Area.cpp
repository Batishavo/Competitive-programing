#include <bits/stdc++.h>

using namespace std;

pair<int, long long> best_cost_area(int mat[][110], int n, int m,long long k)
{

    //Valores a retornar
    long long best_cost = 0;
    int best_area = 0;


    //iterar soble todas las filas
    for (int i = 0; i < n; i++)
    {
        //iterar sobre esta fila en adelante
        for (int j = i; j < n; j++)
        {
          
            //Valores de la iteracion actual
            int area = 0;
            int cost = 0;
            int start = 0;

            //iteras sobre las columnas
            for (int col = 0; col < m; col++)
            {

                int col_sum = mat[j][col];

                if (i > 0)
                {
                    col_sum -= mat[i - 1][col];
                }
                cost += col_sum;

                while(cost >k){
                    cost -=mat[j][start];
                    if(i>0){
                        cost += mat[i-1][start];
                    }
                    start++;
                }

                area = (col-start+1)*(j-i+1);

                if(area == best_area && cost< best_cost){
                    best_cost = cost;
                }
                if(area>best_area){
                    best_area = area;
                    best_cost = cost;
                }

            }
        }
    }

    return {best_area, best_cost};
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;
    int n;
    int m;
    int cont = 0;
    
    long long k;

    int mat[110][110];

    cin >> t;

    while (t--)
    {

        cin >> n >> m >> k;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                if(i>0){
                    mat[i][j] += mat[i-1][j];
                }
            }
        }

        pair<int, long long> actual_best_cost_area = best_cost_area(mat, n, m,k);

        printf("Case #%d: %d %lld\n", ++cont, actual_best_cost_area.first, actual_best_cost_area.second);
    }

    return 0;
}