#include <bits/stdc++.h>

using namespace std;

int n,
    m,
    ini_i,
    ini_j,
    fin_i,
    fin_j;

char mat[110][110];

string cad;

pair<int, int> mov[5] = 
    {
        {0 ,  1}, 
        {1 ,  0}, 
        {-1,  0}, 
        {0 , -1}
    }
;

bool dif(int arr[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (arr[i] == arr[j])
            {
                return false;
            }
        }
    }

    return true;
}

int new_position_i(char num,int arr[]){
    int tmp = num-'0';
    return mov[arr[tmp]].first;
}

int new_position_j(char num,int arr[]){
    int tmp = num-'0';
    return mov[arr[tmp]].second;
}

bool posible(int arr[])
{

    int actual_i=ini_i,
        actual_j=ini_j;

    for(int i=0;i<cad.size();i++){

        actual_i += new_position_i(cad[i],arr);
        actual_j += new_position_j(cad[i],arr);

        if(
            actual_i <0 
            || actual_i>=n
            || actual_j <0
            || actual_j >=m
            || mat[actual_i][actual_j] =='#'
        ){
            return false;
        }

        if(actual_i == fin_i && actual_j == fin_j){
            return true;
        }
            
    }

    return false;
}

int All_Ways()
{

    int cont = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int l = 0; l < 4; l++)
                {
                    int aux[5] = {i, j, k, l};
                    if (dif(aux) &&
                        posible(aux))
                    {
                        cont++;
                    }
                }
            }
        }
    }

    return cont;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];

            if(mat[i][j]=='S'){
                ini_i=i;
                ini_j=j;
            }
            else if(mat[i][j]=='E'){
                fin_i=i;
                fin_j=j;
            }
        }
    }

    cin >> cad;

    cout << All_Ways() << endl;

    return 0;
}