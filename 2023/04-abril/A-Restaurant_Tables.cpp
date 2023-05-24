#include <bits/stdc++.h>

using namespace std;

int aux,
    denied,
    n,
    one,
    one_two,
    two;

int main()
{

    cin >> n >> one >> two;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        if (aux == 1)
        {
            if (one > 0)
            {
                one--;
            }
            else if (two > 0)
            {
                two--;
                one_two++;
            }
            else if (one_two > 0)
            {
                one_two--;
            }

            else
            {
                denied++;
            }
        }
        else
        {
            if (two > 0)
            {
                two--;
            }
            else
            {
                // cout << i << " " << aux << endl;
                denied += 2;
            }
        }
    }
    cout << denied << endl;

    return 0;
}