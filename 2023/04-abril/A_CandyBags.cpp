#include <bits/stdc++.h>

using namespace std;

int n,
    p1,
    p2;

int brother1[2000],
    brother2[2000];

bool flag = 1;

int main()
{

    cin >> n;
    p1 = 1;
    p2 = n * n;
    for (int i = 0; i < (n * n) / 4; i++)
    {
        cout <<p1<<" "<<p2<<" ";
        p1++;
        p2--;
    }
    cout << endl;
    for (int i = 0; i < (n * n) / 4; i++)
    {
        cout <<p1<<" "<<p2<<" ";
        p1++;
        p2--;
    }
    cout << endl;
    return 0;
}