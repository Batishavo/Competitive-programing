#include <bits/stdc++.h>

using namespace std;

const int limit = (10e5) + 10;

int t,
    n,
    k;

long long arr[limit],
    ant,
    actual;

bool flag;

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> n >> k;

        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }

        ant = INT_MAX;
        flag = true;

        for (int i = k - 1; i >= 1; i--)
        {

            actual = arr[i] - arr[i - 1];

            if (actual > ant)
            {   
                //cout<<actual<<" "<<i<<endl;
                flag = false;
                break;
            }

            ant = actual;
        }
        if (flag)
        {
            if (n == k)
            {
                if (arr[0] <= ant)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                int num = n - k + 1,
                    aux = arr[0] % num == 0 ? 0 : 1;

                if (arr[0] >= 0)
                {
                    if (arr[0] < ant || (arr[0] / num) + aux <= ant)
                    {
                        cout << "YES\n";
                    }
                    else
                    {
                        cout << "NO" << endl;
                    }
                }
                else
                {
                    if((num<=abs(arr[0])))
                    {
                        if ((arr[0] / num) + aux <= ant)
                        {
                            cout << "YES\n";
                        }
                        else
                        {
                            cout << "NO" << endl;
                        }
                    }
                    else{
                        cout << "NO" << endl;
                    }
                }
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}