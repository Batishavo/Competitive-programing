#include <bits/stdc++.h>

using namespace std;

const int limit = 10e5 + 10;

vector<pair<int, int>> odd,
    even,
    used;

int n,
    arr[limit];

bool order(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            //cout<<"X"<<endl;
            even.push_back({arr[i], i});
        }
        else
        {
            odd.push_back({arr[i], i});
        }
    }

    if (odd.size() < even.size())
    {
        used = odd;
    }
    else
    {
        used = even;
    }
    sort(used.begin(), used.end(), order);
    int p = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == used[p].first)
        {
            continue;
        }
        if (p >= used.size())
        {
            break;
        }
        if ((arr[i] + used[p].first) % 2 == 1)
        {
            //cout << arr[i] <<" "<<used[p].first<<endl;
            if (arr[i] > used[p].first && used[p].second > i)
            {
                swap(arr[i], arr[used[p].second]);
                p++;
            }
            else if (arr[i] < used[p].first && used[p].second < i)
            {
                swap(arr[i], arr[used[p].second]);
                p++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}