#include <bits/stdc++.h>

using namespace std;

const int limit = 10e3 + 10;

int n,
    m,
    k,
    t;

pair<int, int> waste[limit];

bool order(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

long long binary_search(int y, int x)
{

    int ini = 0,
        fin = k;

    while (ini < fin)
    {

        int mid = (ini + fin) / 2 + 1;

        if (waste[mid].first == y && waste[mid].second == x)
        {
            return -1;
        }
        else if (order({y, x}, waste[mid]))
        {
            fin = mid - 1;
        }
        else
        {
            ini = mid;
        }
    }

    return ini;
}

string answer(int y, int x)
{

    long long res = binary_search(y, x);

    if (res == -1)
    {
        return "Waste";
    }

    long long num = ((y-1) * m) + x - res;

    //cout<<"total: "<<num<<" res: "<<res<<" pos: "<<((y-1) * m) + x <<endl;

    switch (num % 3)
    {

    case 1:
        return "Carrots";
        break;
    case 2:
        return "Kiwis";
        break;
    default:
        return "Grapes";
        break;
    }
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    cin >> n >> m >> k >> t;

    waste[0] = {0, 0};

    for (int i = 1; i <= k; i++)
    {
        cin >> waste[i].first >> waste[i].second;
    }

    sort(waste, waste + k + 1, order);

    for (int i = 0; i < t; i++)
    {
        int y,
            x;

        cin >> y >> x;

        cout << answer(y, x) << endl;
    }

    return 0;
}