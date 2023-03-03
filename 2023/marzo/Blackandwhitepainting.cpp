#include <bits/stdc++.h>

using namespace std;

int n, m;
bool pos;
long long cont = 0;
int main()
{

    while (scanf("%d %d %d", &n, &m, &pos))
    {
        if (n == 0 && m == 0 && pos == 0)
        {
            break;
        };
        for (int i = 0; i < n - 7; i++)
        {
            //cout<<"x";
            if (pos)
            {
                cont += m-7-((m - 7) / 2);
            }
            else
            {
                cont += (m - 7) / 2;
            }
            pos = !pos;
        }
        cout << cont << endl;
        cont = 0;
    }

    return 0;
}
// 333220842500
// 799700028