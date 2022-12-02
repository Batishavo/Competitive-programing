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
                // cout<<actual<<" "<<i<<endl;
                flag = false;
                break;
            }

            ant = actual;
        }
        if (k == 1)
        {
            cout << "YES" << endl;
            continue;
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
                    //cout<<"---------"<<ant<<endl;
                    if(ant == 0 || (arr[0]==-1 && arr[0]<=ant && ant>=0)){
                        cout << "YES\n";
                    }
                    else if ((num <= abs(arr[0])))
                    {   
                        
                        //cout<<"---------"<<endl;
                        //printf("%d %d %d %d %d\n",arr[0],num,aux,(arr[0] / num),ant);
                        if (((arr[0] / num) <= ant))
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