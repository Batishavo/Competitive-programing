#include <bits/stdc++.h>

using namespace std;

int t,
    n,
    minimo,
    Offices[5],
    mat[30][30];

pair<int, int> convert(int area)
{
    return {area / 5, area % 5};
}

<<<<<<< HEAD
bool compara_ofices(int comp_ofices[])
{
    for (int i = 0; i < 5; i++)
    {
        if (comp_ofices[i] < Offices[i])
        {
            return true;
        }
        else if (comp_ofices[i] > Offices[i])
        {
            return false;
=======
int Calcular_Area(pair<int, int> area)
{
    for (int i = 0; i < 5; i++)
    {
        if (comp_ofices[i] < Offices[i])
        {
            return true;
>>>>>>> b4c0824 (avance en fuersas brutas)
        }
        else if (comp_ofices[i] > Offices[i])
        {
            return false;
        }
    }
    return false;
}

void Calcular(int ofice1, int ofice2, int ofice3, int ofice4, int ofice5)
{

    int sum = 0,
        comp_ofices[10]={ofice1, ofice2, ofice3, ofice4,ofice5};

    pair<int, int> tmp_ofices[10];

    tmp_ofices[1] = convert(ofice1);
    tmp_ofices[2] = convert(ofice2);
    tmp_ofices[3] = convert(ofice3);
    tmp_ofices[4] = convert(ofice4);
    tmp_ofices[5] = convert(ofice5);

    for (int i = 1; i <= 5; i++)
    {
        sum += Calcular_Area(tmp_ofices[i]);
    }
    // cout<<sum<<" "<<minimo<<endl;
    if (sum < minimo)
    {
        minimo=sum;
        Offices[0] = ofice1;
        Offices[1] = ofice2;
        Offices[2] = ofice3;
        Offices[3] = ofice4;
        Offices[4] = ofice5;
    }
    else if (sum == minimo)
    {
        if (compara_ofices(comp_ofices))
        {
            Offices[0] = ofice1;
            Offices[1] = ofice2;
            Offices[2] = ofice3;
            Offices[3] = ofice4;
            Offices[4] = ofice5;
        }
    }
}

void Brute_Force()
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 25; j++)
        {
            for (int k = j + 1; k < 25; k++)
            {
                for (int l = k + 1; l < 25; l++)
                {
                    for (int m = l + 1; m < 25; m++)
                    {
                        Calcular(i, j, k, l, m);
                    }
                }
            }
        }
    }
}

void clean()
{
    for (int i = 0; i < 5; i++)
    {
        Offices[i]=0;
        for (int j = 0; j < 5; j++)
        {
            mat[i][j] = 0;
        }
    }
    minimo = INT_MAX;
}

int main()
{
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {
        clean();

        cin >> n;

        for (int i = 0; i < n; i++)
        {

            int x,
                y,
                val;

            cin >> y >> x >> val;

            mat[y][x] = val;
        }

        Brute_Force();

        for (int i = 0; i < 5; i++)
        {
            cout << Offices[i];
            if (i != 4)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}