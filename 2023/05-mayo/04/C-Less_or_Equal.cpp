#include <bits/stdc++.h>

using namespace std;

int n,
    m;

vector<int> nums;

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int aux;
        cin >> aux;
        nums.push_back(aux);
    }

    sort(nums.begin(), nums.end());
    if (m == 0)
    {
        if (nums[0] == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    else if ((m == n || nums[m] != nums[m - 1]))
    {
        cout << nums[m - 1] << endl;
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}