#include <bits/stdc++.h>

using namespace std;

int t, n;
long long cont0, cont1, cont, mayor;

string cad;

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> n >> cad;
        cont1 = 0;
        cont0 = 0;
        cont = 1;
        for (int i = 0; i < n; i++)
        {
            if (cad[i] == '1')
            {
                cont1++;
            }
            else
            {
                cont0++;
            }
        }
        mayor = cont1 * cont0;
        for (int i = 1; i < n; i++)
        {
            if (cad[i] != cad[i - 1])
            {
                long long aux = pow(cont, 2);
                mayor = max(mayor, aux);
                cont = 1;
            }
            else
            {
                cont++;
            }
        }
        long long aux = pow(cont, 2);
        mayor = max(mayor, aux);
        //cout << "--";
        cout << mayor << endl;
    }

    return 0;
}