#include <bits/stdc++.h>

using namespace std;

string cad;

int q;

vector<stack<char>> my_stacks;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    while (true)
    {
        cin >> cad;

        if (cad == "end")
        {
            break;
        }

        stack<char> tmp;
        tmp.push(cad[0]);
        my_stacks.push_back(tmp);

        for (int i = 1; i < cad.size(); i++)
        {

            bool flag = 1;

            for (int j = 0; j < my_stacks.size(); j++)
            {
                if (my_stacks[j].top() >= cad[i])
                {
                    my_stacks[j].push(cad[i]);
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                stack<char> tmp;
                tmp.push(cad[i]);
                my_stacks.push_back(tmp);
            }
            //alphabet[cad[i]]--;
        }

        printf("Case %d: %d\n", ++q, my_stacks.size());
        my_stacks.clear();
    }

    return 0;
}