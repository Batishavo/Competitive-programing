#include <bits/stdc++.h>

using namespace std;

const int limit = 50010;

int t,
    n,
    m,
    aux,
    pos,
    pos2,
    mayor,
    menor;

queue<int> v;

pair<int, int> nums[limit],
    used[limit];

bool how(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

bool no_number(pair<int, int> a)
{
    return a.first == 0 && a.second == 0;
}

void clean()
{
    for (int i = 0; i <= mayor + 1; i++)
    {
        nums[i] = {0, 0};
    }
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {

        cin >> n;
        mayor = 0;
        pos = 1;
        pos2 = 1;
        menor = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            cin >> m;
            for (int j = 1; j <= m; j++)
            {
                cin >> aux;
                nums[aux] = {i, aux};
                mayor = max(aux, mayor);
                menor = min(aux, menor);
            }
        }
        // cout<<"----------"<<endl;
        for (int i = 0; i <= mayor + 1; i++)
        {
            if (no_number(nums[i]))
            {
                continue;
            }
            used[pos++] = nums[i];
        }
        sort(used, used + pos, how);

        /*for(int i=1;i<pos;i++){
            cout<<used[i].first<<" "<<used[i].second<<endl;
        }
        cout<<"--------"<<endl;*/
        for (int i = 1; i < pos; i++)
        {
            if (pos2 > n)
            {
                break;
            }
            else if (used[i].first > pos2)
            {
                break;
            }
            else if (used[i].first < pos2)
            {
                continue;
            }
            pos2++;
            v.push(used[i].second);
        }
        //cout<<"---"<<pos2<<" "<<n<<endl;
        if (pos2-1==n)
        {
            while (!v.empty())
            {
                cout << v.front() << " ";
                v.pop();
            }
        }
        else
        {
            cout << "-1";
        }
        cout << endl;
        clean();
        while (!v.empty())
        {
            v.pop();
        }
    }

    return 0;
}