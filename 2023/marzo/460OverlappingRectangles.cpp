#include <bits/stdc++.h>

using namespace std;

int t,
    rx1,
    ry1,
    rx2,
    ry2,
    square1[10],
    square2[10];

bool flag = 1;

void calculaX(int X1, int X2, int x1, int x2)
{
    if (x1 > X1 && x1 < X2 && x2 > X1 && x2 < X2)
    {
        rx1 = x1;
        rx2 = x2;
        return;
    }
    if (x1 > X1 && x1 < X2)
    {
        rx1 = x1;
        rx2 = X2;
        return;
    }

    if (x2 > X1 && x2 < X2)
    {
        rx1 = X1;
        rx2 = x2;
        return;
    }

    flag = 0;
}

void calculaY(int Y1, int Y2, int y1, int y2)
{
    if (y1 > Y1 && y1 < Y2 && y2 > Y1 && y2 < Y2)
    {
        ry1 = y1;
        ry2 = y2;
        return;
    }
    if (y1 > Y1 && y1 < Y2)
    {
        ry1 = y1;
        ry2 = Y2;
        return;
    }

    if (y2 > Y1 && y2 < Y2)
    {
        ry1 = Y1;
        ry2 = y2;
        return;
    }

    flag = 0;
}

int main()
{
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    scanf("%d", &t);

    while (t--)
    {

        for (int i = 0; i < 4; i++)
        {
            cin >> square1[i];
        }

        for (int i = 0; i < 4; i++)
        {
            cin >> square2[i];
        }
        int cont = 0;
        for (int i = 0; i < 4; i++)
        {
            if (square1[i] == square2[i])
            {
                cont++;
            }
        }
        if (cont == 4)
        {
            for (int i = 0; i < 4; i++)
            {
                cout << square2[i];
                if (i != 3)
                {
                    cout << " ";
                }
                cout << endl;
            }
            continue;
        }
        // TODO : si algun lado es igual

        flag = 1;
        if (square1[0] == square2[0] && square1[2] == square2[2])
        {
            if (square1[1] - square1[3] > square2[1] - square2[3])
            {
                calculaY(square1[1], square1[3], square2[1], square2[3]);
            }
            else
            {
                calculaY(square2[1], square2[3], square1[1], square1[3]);
            }
            if (flag)
            {
                cout << square1[0] << " " << ry1 << " " << square1[2] << " " << ry2 << endl<<endl;
            }
            else
            {
                cout << "No Overlap"<<endl<<endl;
            }
            continue;
        }

        if (square1[1] == square2[1] && square1[3] == square2[3])
        {
            if (square1[2] - square1[0] > square2[2] - square2[0])
            {
                calculaX(square1[0], square1[2], square2[0], square2[2]);
            }
            else
            {
                calculaX(square2[0], square2[2], square1[0], square1[2]);
            }
            if (flag)
            {
                cout << rx1 << " " << square1[1] << " " << rx2 << " " << square1[2] << endl<<endl;
            }
            else
            {
                cout << "No Overlap"<<endl<<endl;
            }
            continue;
        }
        ////////////////////////////////////////////////////////////////////////////////
        if (square1[2] - square1[0] > square2[2] - square2[0])
        {
            calculaX(square1[0], square1[2], square2[0], square2[2]);
        }
        else
        {
            calculaX(square2[0], square2[2], square1[0], square1[2]);
        }
        if (square1[1] - square1[3] > square2[1] - square2[3])
        {
            calculaY(square1[1], square1[3], square2[1], square2[3]);
        }
        else
        {
            calculaY(square2[1], square2[3], square1[1], square1[3]);
        }

        if (flag)
        {
            cout << rx1 << " " << ry1 << " " << rx2 << " " << ry2 << endl<<endl;
        }
        else
        {
            cout << "No Overlap"<<endl<<endl;
        }
    }

    return 0;
}