#include <bits/stdc++.h>

using namespace std;

string cad[5];

int tercia()
{
    int cont = 0;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            if (cad[i][0] == cad[j][0])
            {
                sum++;
            }
        }
        cont = max(cont, sum);
    }
    return 3 - cont;
}

int escalera()
{
    int cont = 0;
    for (int i = 0; i < 3; i++)
    {
        int sum = 1,
            menor = cad[i][0],
            mayor = cad[i][0];

        for (int j = 0; j < 3; j++)
        {
            if (cad[i][1] == cad[j][1])
            {
                if (cad[j][0] > mayor && cad[j][0] - mayor == 1)
                {
                    sum++;
                }
                if(cad[j][0] < menor && menor-cad[j][0]==1){
                    sum++;
                }
            }
        }
        cont = max(cont, sum);
    }
    return 3 - cont;
}

int main()
{

    for (int i = 0; i < 3; i++)
    {
        cin >> cad[i];
    }

    cout << min(tercia(), escalera())<<endl;

    return 0;
}