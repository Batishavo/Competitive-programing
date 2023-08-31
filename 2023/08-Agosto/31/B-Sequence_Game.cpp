#include <bits/stdc++.h>

using namespace std;

const int limit = 2e5 + 10;

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;
    int n;
    int pos;

    int arr[limit];
    int answer[limit*2];

    scanf("%d", &t);

    while (t--)
    {

        pos = 1;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
           cin >> arr[i];
        }

        answer[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] <= arr[i])
            {
                answer[pos++] = arr[i];
            }
            else
            {
                answer[pos++] = 1;
                answer[pos++] = arr[i];
            }
        }

        cout << pos << endl;
        for (int i = 0; i < pos; i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }

    return 0;
}