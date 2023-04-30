#include <bits/stdc++.h>

using namespace std;

int t;

string cad,
    n1,
    n2;

bool flag = true;

int cadToNumber(string cad)
{
    int num = 0,
        mul = 1;

    for (int i = cad.length() - 1; i >= 0; i--)
    {
        num += (cad[i] - '0') * mul;
        mul *= 10;
    }

    return num;
}

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> cad;

        for (int i = 0; i < cad.size(); i++)
        {
            if (cad[i] == '+')
            {
                flag = !flag;
                continue;
            }
            if (flag)
            {
                n1 += cad[i];
            }
            else
            {
                n2 += cad[i];
            }
        }
        flag = !flag;

        printf("%d\n", cadToNumber(n1) + cadToNumber(n2));
        n1 = "";
        n2 = "";
    }

    return 0;
}