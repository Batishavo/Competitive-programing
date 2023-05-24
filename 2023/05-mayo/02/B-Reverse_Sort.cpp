#include <bits/stdc++.h>

using namespace std;

int t,
    n,
    cero;

string cad;

vector<int> result;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {

        result.clear();

        cero = 0;

        cin >> n;

        cin >> cad;

        for (int i = 0; i < n; i++)
        {
            if (cad[i] == '0')
            {
                cero++;
            }
        }
        //cout<<cero<<endl;
        for (int i = 0; i < n; i++)
        {
            if (cad[i] == '1')
            {
                if (i < cero)
                {
                    result.push_back(i + 1);
                }
            }
            else if(cad[i] == '0')
            {
                if (i >= cero)
                {
                    result.push_back(i + 1);
                }
            }
        }
        if (result.size() >= 1)
        {
            cout << "1" << endl;
            cout<<result.size()<<" ";
        }
        else
        {
            cout << "0" << endl;
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        if (result.size() > 0)
            cout << endl;
    }

    return 0;
}