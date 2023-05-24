#include <bits/stdc++.h>

using namespace std;

long long n;

string codeforces = "codeforces";

int arr[15];

void llenar()
{

    int pos = 0;

    while (true)
    {

        long long num = 1;

        for (int i = 0; i < 10; i++)
        {
            num *= arr[i];
        }

        if (num >= n)
        {
            break;
        }

        arr[pos]++;
        pos = (pos + 1) % 10;
    }
}

int main()
{

    for(int i = 0; i < 10; i++) {
        arr[i] = 1;
    }

    cin >> n;

    llenar();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j<arr[i]; j++)
        {
            cout << codeforces[i];
        }
    }
    cout << endl;

    return 0;
}