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
            if (cad[i] == cad[j])
            {
                sum++;
            }
        }
        cont = max(cont, sum);
    }
    return 3 - cont;
}

int en_medio()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (cad[i][1] == cad[j][1] &&
                abs(cad[i][0] -cad[j][0])==2)
            {
                return 1;
            }
        }
    }
    return 2;
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
            if(i==j){
                continue;
            }
            if (cad[i][1] == cad[j][1])
            {
                if (cad[j][0] > mayor && cad[j][0] - mayor == 1)
                {
                    sum++;
                    mayor = cad[j][0];
                }
                if (cad[j][0] < menor && menor - cad[j][0] == 1)
                {
                    sum++;
                    menor = cad[j][0];
                }
            }
        }

        cont = max(cont, sum);
    }
    return min(3 - cont,en_medio());
}

int main()
{

    for (int i = 0; i < 3; i++)
    {
        cin >> cad[i];
    }

    //cout<<tercia()<<endl<<escalera()<<endl;

    cout << min(tercia(), escalera()) << endl;

    return 0;
}