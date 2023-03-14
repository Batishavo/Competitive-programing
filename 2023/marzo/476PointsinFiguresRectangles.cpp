#include <bits/stdc++.h>

using namespace std;

char caracter;

int pos = 0,
    cont = 0;

vector<double> rectangles[20];

float aux,
    xp,
    yp;

int count(double x1, double x2, double y1, double y2)
{
    return (x2 - x1) * (yp - y1) - (xp - x1) * (y2 - y1) > 0 ? 1 : 0;
}

int main()
{

    while (cin >> caracter)
    {
        if (caracter == '*')
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            cin >> aux;
            rectangles[pos].push_back(aux);
        }
        pos++;
    }

    while (cin >> xp >> yp)
    {
        bool flag = 0;
        if (xp >= 9999.9 * 1.0 && yp >= 9999.9 * 1.0)
        {
            break;
        }
        for (int i = 0; i < pos; i++)
        {
            int cont = 0;
            cont+=count();
            cont+=count();
            cont+=count();
            cont+=count();

            if (cont >= 4)
            {
                printf("Point %d is contained in figure %d\n", cont, i + 1);
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            printf("Point %d is not contained in any \n", cont);
        }
    }

    return 0;
}