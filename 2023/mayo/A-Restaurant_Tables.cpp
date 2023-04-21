#include <bits/stdc++.h>

using namespace std;

int aux,
    denied,
    n,
    one,
    p_one,
    p_two,
    two;

int main()
{

    cin >> n >> one >> two;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        if (aux == 1)
        {
            if (p_one < one)
            {
                p_one++;
            }
            else if (p_two < two)
            {
                two--;
                one++;
            }
            else
            {
                //cout << i << " " << aux << endl;
                denied++;
            }
        }
        else
        {
            if (p_two < two)
            {
                p_two++;
            }
            else
            {
                //cout << i << " " << aux << endl;
                denied += 2;
            }
        }
    }
    cout << denied << endl;

    return 0;
}