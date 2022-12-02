#include <bits/stdc++.h>

using namespace std;

int val = 362880, mat[15], n;
string cad;

void res(int num, string cad)
{

    if (num >= val)
    {

        if (num == val)
        {
            cout << cad << endl;
        }
        return;
    }
    res(num * 2, cad + " 2");
    res(num * 6, cad + " 3");
    res(num * 120, cad + " 5");
    res(num * 5040, cad + " 7");
}

int main()
{

    // cout << "entra" << endl;

    // res(1, "");
    cin >> n >> cad;

    for (int i = 0; i < n; i++)
    {
        if (cad[i] == '4')
        {
            mat[3]++;
            mat[2] += 2;
        }
        else if (cad[i] == '6')
        {
            mat[5]++;
            mat[3]++;
        }
        else if (cad[i] == '8')
        {
            mat[2] += 3;
            mat[7]++;
        }

        else if (cad[i] == '9')
        {
            mat[2]++;
            mat[3] += 2;
            mat[7]++;
        }
        else
        {
            mat[cad[i] - '0']++;
        }
    }
    for (int i = 9; i >= 2; i--)
    {
        for (int j = 0; j < mat[i]; j++)
        {
            cout << i;
        }
    }
    cout << endl;

    return 0;
}