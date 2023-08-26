#include <bits/stdc++.h>

using namespace std;

string cad;
int mov;
int corrimiento;

char cosa;
void encriptar()
{

    for (int i = 1; i < cad.size(); i += mov)
    {

        if (i + mov >= cad.size())
        {
            reverse(cad.begin() + i, cad.end());
            break;
        }
        reverse(cad.begin() + i, cad.begin() + i + mov);
    }

    for (int i = 1; i < cad.size(); i++)
    {
        cad[i] = cad[i] + corrimiento;
    }
}

void desencriptar()
{
    for (int i = 1; i < cad.size(); i += mov)
    {

        if (i + mov >= cad.size())
        {
            reverse(cad.begin() + i, cad.end());
            break;
        }

        reverse(cad.begin() + i, cad.begin() + i + mov);
    }

    for (int i = 1; i < cad.size(); i++)
    {
        cad[i] = cad[i] - corrimiento;
    }
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    cin >> cad;
    cin >> cosa >> mov >> cosa >> corrimiento;

    if (cad[0] == 'E' || cad[0] == 'e')
    {
        encriptar();
    }
    else
    {
        desencriptar();
    }
    for (int i = 1; i < cad.size(); i++)
    {
        if (cad[i] > 'Z')
        {
            cad[i] -= 32;
        }
        cout << cad[i];
    }
    cout << endl;

    return 0;
}