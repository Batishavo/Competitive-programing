#include <bits/stdc++.h>

using namespace std;

const int limit = 1000;

int b,
    v,
    q,
    nums[limit];

string cads[limit][4];

int search(string cad)
{
    for (int i = 0; i < v; i++)
    {
        if (cads[i][0] == cad)
        {
            return i;
        }
    }
    return -1;
}

unsigned long long bynaryToDecimal(string cad)
{
    // cout<<endl<< cad<<endl;
    unsigned long long num = 0;
    unsigned long long sum = 1;

    for (int i = cad.length() - 1; i >= 0; i--)
    {
        if (cad[i] == '1')
        {
            num += sum;
        }
        // cout << sum << endl;
        sum *= 2;
    }
    // cout<<num << endl;
    return num;
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    while (cin >> b >> v)
    {
        for (int i = 0; i < v; i++)
        {
            cin >> cads[i][0] >> nums[i];
        }
        for (int i = 0; i < v; i++)
        {
            string aux,
                tmp = "";
            for (int j = 0; j < nums[i]; j++)
            {
                cin >> aux;
                tmp += aux;
            }
            cads[i][1] = tmp;
        }
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            string cad;
            cin >> cad;
            int num = search(cad);
            if (num != -1)
            {
                unsigned long long res = bynaryToDecimal(cads[num][1]);
                cout << cad << "=" << res << endl;
            }
            else
            {
                cout << cad << "=" << endl;
            }
        }
    }
    // cout << "x";
    return 0;
}