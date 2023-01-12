#include <bits/stdc++.h>

using namespace std;

int t, n, m, cont, aux;
string tmp;
queue<int> l, r;

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> n >> m;
        n *= 100;
        for (int i = 0; i < m; i++)
        {
            cin >> aux >> tmp;
            if (tmp == "left")
            {
                l.push(aux);
            }
            else
            {
                r.push(aux);
            }
        }
        //cout << "---" << endl;
       //  cout << r.size() << r.empty();
        while (!l.empty() || !r.empty())
        {
            cont++;
            int acumulado = 0;
            //printf("**%d %d %d\n", acumulado, l.empty(), r.empty());
            if (cont % 2 == 1)
            {
                if (!l.empty())
                {
                    while (!l.empty())
                    {
                        if (acumulado + l.front() <= n)
                        {
                            acumulado += l.front();
                            //printf("%d %d\n", l.front(), acumulado);
                            l.pop();
                        }
                        else
                            break;
                    }
                }
            }
            else 
            {
                if (!r.empty())
                {
                    while (!r.empty())
                    {
                        if (acumulado + r.front() <= n)
                        {
                            acumulado += r.front();
                            //printf("%d %d\n", r.front(), acumulado);
                            r.pop();
                        }
                        else
                            break;
                    }
                }
            }
           // system("pause");
        }
        //cout << "--";
        cout << cont << endl;
        cont = 0;
    }

    return 0;
}