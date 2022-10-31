#include <bits/stdc++.h>

using namespace std;

string cad;

int main()
{

    cin >> cad;

    if(cad.size()<4){
        cout<<0<<endl;
        return 0;
    }

    int cont = 0,
        bear_index(-1),
        l = cad.size(),
        left = 0;

    for (int i = 0; i < cad.size() - 3; i++)
    {
        if (cad[i] == 'b' && cad[i + 1] == 'e' && cad[i + 2] == 'a' && cad[i + 3] == 'r')
        {
            int right = (l - (i + 3)) - 1;
            if (bear_index == -1)
            {
                left = i;
            }
            else
            {
                left = i - (bear_index + 1);
            }

            cont += ((right) * (left)) + 1 + (right) + (left);
            bear_index = i;
        }
    }
    cout << cont << endl;
    return 0;
}