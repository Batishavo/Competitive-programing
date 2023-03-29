#include <bits/stdc++.h>

using namespace std;

const int limit = 1005;

int n,
    k,
    pos,
    arr[limit],
    answer[limit * limit][4],
    total;

int main()
{

    cin >> n >> k;

    if (n <= 2)
    {
        cout << "-1" << endl;
    }
    else
    {
        int num = ((n - 1) * (n)) / 2,
            mol = num % k,
            cant = num / k;
        if (k <= num / n)
        {
            // cout<<num<<endl;
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (arr[i] < k)
                    {
                        arr[i]++;
                        answer[pos][0] = i;
                        answer[pos][1] = j;
                        pos++;
                        if(arr[i] == k)total++;
                    }
                    else if (arr[j] < k)
                    {
                        answer[pos][0] = j;
                        answer[pos][1] = i;
                        arr[j]++;
                        pos++;
                        if(arr[j] == k)total++;
                    }

                    if(total==n){
                        break;
                    }
                }
                if(total==n){
                    break;
                }
            }
            cout << pos << endl;
            for (int i = 0; i < pos; i++)
            {
                cout << answer[i][0] << " " << answer[i][1] << endl;
            }
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}