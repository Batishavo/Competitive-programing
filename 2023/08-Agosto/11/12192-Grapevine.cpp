#include <bits/stdc++.h>

using namespace std;

const int limit = 510;

int mat[limit][limit];

int binary_search_l(int fin, int l, int pos)
{

    int ini = 0;

    while (ini < fin)
    {

        int mid = ini + (fin - ini) / 2;

        // cout<<mid<<endl;

        if (mat[mid][pos] < l)
        {
            ini = mid + 1;
        }
        else
        {
            fin = mid;
        }
    }

    if (mat[fin][pos] < l)
    {
        return -1;
    }
    return ini;
}

int binary_search_r(int i, int j, int n, int m, int fin, int num)
{
    int ini = 0;

    while (ini < fin)
    {

        int mid = (ini + fin) / 2 + 1;

        if (mat[i + mid][j + mid] > num)
        {
            fin = mid - 1;
        }
        else
        {
            ini = mid;
        }
    }

    return ini;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int m;
    int q;
    int mayor;

    while (cin >> n >> m)
    {

        if (n == 0 && m == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }

        cin >> q;

        while (q--)
        {
            mayor = 0;
            int l;
            int r;

            cin >> l >> r;

            for (int j = 0; j < m; j++)
            {
                int pos_i = binary_search_l(n - 1, l, j);

                // printf("l: %d pL: %d j: %d\n",l,pos_l,j);
                if (pos_i != -1 && mat[pos_i][j]>=l && mat[pos_i][j]<=r)
                {
                    int fin = min(n - pos_i - 1, m - j - 1);
                    mayor = max(mayor, binary_search_r(pos_i, j, n, m, fin, r) + 1);
                }
            }

            cout << mayor << endl;
        }
        cout << "-\n";
    }

    return 0;
}