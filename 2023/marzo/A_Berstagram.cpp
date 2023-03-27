#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

int pos[limit],
    actual[limit],
    n,
    m,
    aux;

pair<int, int> nums[limit];

void cambio(int aux)
{
    if (pos[aux] == 1)
    {
        return;
    }

    int tmp = actual[pos[aux] - 1];
    pos[aux]--;
    pos[tmp]++;
    actual[pos[aux]] = aux;
    actual[pos[tmp]] = tmp;
    // printf("%d %d \n", aux, tmp);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << pos[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << actual[i] << " ";
    // }
    // cout << endl;
    // cambio
    nums[aux].first = min(pos[aux], nums[aux].first);
    nums[aux].second = max(pos[aux], nums[aux].second);
    /////
    nums[tmp].first = min(pos[tmp], nums[tmp].first);
    nums[tmp].second = max(pos[tmp], nums[tmp].second);
}

int main()
{
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        pos[i] = i;
        actual[i] = i;
        nums[i] = {i, i};
    }
    for (int i = 0; i < m; i++)
    {
        cin >> aux;

        cambio(aux);
    }
    //cout << "--------" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << nums[i].first << " " << nums[i].second << endl;
    }

    return 0;
}