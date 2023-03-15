#include <bits/stdc++.h>

using namespace std;

int t,
    square1[10],
    square2[10],
    squares_answer[10];

bool flag = 0,
     spaces = 0;

bool equ()
{
    for (int i = 0; i < 4; i++)
    {
        if (square1[i] != square2[i])
        {
            return false;
        }
    }
    return true;
    ;
}

bool posible(int square1_ini, int square1_fin, int square2_ini, int square2_fin)
{

    if (
        (square2_ini > square1_ini && square2_ini < square1_fin) ||
        (square2_fin > square1_ini && square2_fin < square1_fin) ||
        (square1_ini > square2_ini && square1_ini < square2_fin) ||
        (square1_fin > square2_ini && square1_fin < square2_fin))
    {
        return true;
    }

    return false;
}

void printanswer()
{
    if (!flag)
    {
        cout << "No Overlap" << endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << squares_answer[i];
        if (i != 3)
        {
            cout << " ";
        }
    }
    cout << endl;
}

int menor(int square1, int square2)
{
    return max(square1,square2);
}

int mayor(int square1, int square2)
{
    return min(square1,square2);
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    scanf("%d", &t);

    while (t--)
    {
        flag = 0;
        if (!spaces)
        {
            spaces = 1;
        }
        else
        {
            cout << endl;
        }
        for (int i = 0; i < 4; i++)
        {
            cin >> square1[i];
        }

        for (int i = 0; i < 4; i++)
        {
            cin >> square2[i];
        }
        ////////////////////////////////
        if (equ())
        {
            for (int i = 0; i < 4; i++)
            {
                squares_answer[i] = square1[i];
            }
            flag = 1;
        }
        else if (
            square1[0] == square2[0] &&
            square1[2] == square2[2] &&
            posible(square1[1], square1[3], square2[1], square2[3]))
        {
            squares_answer[0] = square1[0];
            squares_answer[2] = square1[2];
            squares_answer[1] = menor(square1[1], square2[1]);
            squares_answer[3] = mayor(square1[3], square2[3]);
            flag = 1;
        }
        else if (
            square1[1] == square2[1] &&
            square1[3] == square2[3] &&
            posible(square1[0], square1[2], square2[0], square2[2]))
        {
            squares_answer[1] = square1[1];
            squares_answer[3] = square1[3];
            squares_answer[0] = menor(square1[0], square2[0]);
            squares_answer[2] = mayor(square1[2], square2[2]);
            flag = 1;
        }
        else if (
            posible(square1[1], square1[3], square2[1], square2[3]) &&
            posible(square1[0], square1[2], square2[0], square2[2]))
        {
            squares_answer[0] = menor(square1[0], square2[0]);
            squares_answer[1] = menor(square1[1], square2[1]);
            squares_answer[2] = mayor(square1[2], square2[2]);
            squares_answer[3] = mayor(square1[3], square2[3]);
            flag = 1;
        }
        printanswer();
    }

    return 0;
}