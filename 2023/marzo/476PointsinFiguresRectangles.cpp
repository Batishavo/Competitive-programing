#include <bits/stdc++.h>

using namespace std;

char caracter;

int pos = 0,
    cont = 1;

vector<double> rectangles[20];

float aux,
    xp,
    yp;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    while (cin >> caracter)
    {
        if (caracter == '*')
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            cin >> aux;
            rectangles[pos].push_back(aux * 1.0);
        }
        pos++;
    }

    // cout<<"------------"<<endl;

    while (cin >> xp >> yp)
    {
        if (xp >= 9999.9 && yp >= 9999.9)
        {
            break;
        }
        bool flag = 0;
        for (int i = 0; i < pos; i++)
        {

            if (xp > rectangles[i][0] &&
                xp < rectangles[i][2] &&
                yp < rectangles[i][1] &&
                yp > rectangles[i][3]
            )
            {
                printf("Point %d is contained in figure %d\n", cont, i + 1);
                flag = 1;
            }
        }
        if (!flag)
        {
            printf("Point %d is not contained in any figure\n", cont);
        }
        cont++;
    }

    return 0;
}