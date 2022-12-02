#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> n;
        if (n % 2 == 1)
        {
            n++;
        }
        // cout<<"--";
        cout << n / 2 << endl;
    }

    return 0;
}