#include <bits/stdc++.h>

using namespace std;

string cad;

int n,
    pos;

int main()
{

    cin >> cad >> n;

    while (pos < cad.size() && n > 0)
    {

        int fin = min(int(cad.length()), pos + n+1),
            new_pos = pos;

        char actual = cad[pos];
        //cout << pos << " ";
        for (int i = pos + 1; i < fin; i++)
        {
           // cout<<"entra";
            if (cad[i] > actual)
            {
                new_pos = i;
                actual = cad[i];
            }
        }
        for (int i = new_pos; i > pos; i--)
        {
            swap(cad[i], cad[i - 1]);
        }
        n -= (new_pos - pos);
        pos++;
        //cout << new_pos << " " << actual << endl;
    }

    cout << cad << endl;

    return 0;
}