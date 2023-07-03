#include <bits/stdc++.h>

using namespace std;

int n,
    mayor,
    answer,
    arr[10];

string used;

map<string, int> memo;

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    while (scanf("%d", &n))
    {
        if (n == 0)
        {
            break;
        }

        mayor = 0;
        answer = 0;
        memo.clear();

        while (n--)
        {
            for (int i = 0; i < 5; i++)
            {
                scanf("%d", &arr[i]);
            }
            sort(arr, arr + 5);
            used = "";
            for (int i = 0; i < 5; i++)
            {
                //cout << arr[i] << " ";
                used += to_string(arr[i]) + ',';
            }
            // cout<<endl;
            memo[used]++;
        }

        for (auto x : memo)
        {
            mayor = max(mayor, x.second);
        }

        for (auto x : memo)
        {
            if (mayor == x.second)
            {
                answer += x.second;
                //cout << x.first << endl;
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}
