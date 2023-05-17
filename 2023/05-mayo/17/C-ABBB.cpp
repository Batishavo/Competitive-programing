#include <bits/stdc++.h>

using namespace std;

int t,
    num;

string cad;

stack<char> Shortest_String;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {

        cin >> cad;

        Shortest_String.push(cad[0]);

        for (int i = 1; i < cad.size(); i++)
        {
            if (!Shortest_String.empty() && Shortest_String.top() == 'A' && cad[i] == 'B')
            {
                Shortest_String.pop();
            }
            else
            {
                Shortest_String.push(cad[i]);
            }
        }
        cad = "";
        while (!Shortest_String.empty())
        {
            cad += Shortest_String.top();
            Shortest_String.pop();
        }
        reverse(cad.begin(), cad.end());
        if (cad.size() > 0)
        {
            Shortest_String.push(cad[0]);

            for (int i = 1; i < cad.size(); i++)
            {
                if (!Shortest_String.empty() && Shortest_String.top() == 'B' && cad[i] == 'B')
                {
                    Shortest_String.pop();
                }
                else
                {
                    Shortest_String.push(cad[i]);
                }
            }
        }

        while (!Shortest_String.empty())
        {
            Shortest_String.pop();
            num++;
        }
        printf("%d\n", num);
        num = 0;
    }

    return 0;
}