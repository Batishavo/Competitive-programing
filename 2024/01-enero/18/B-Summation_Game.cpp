#include <bits/stdc++.h>

using namespace std;

const int limit = 20e5;

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int k;
    int n;
    int t;
    int x;

    int arr[limit];

    long long answer;
    long long res;
    long long sum;

    cin >> t;

    while (t--)
    {

        res = 0;
        sum = 0;
        answer = 0;

        cin >> n >> k >> x;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        sort(arr, arr + n);

        for (int i = n - 1; i >= n - x && i >= 0; i--)
        {
            res += arr[i];
            sum -= arr[i];
        }

        //cout<<res<<" "<<sum<<endl;

        answer = sum - res;

        for (int i = n - 1; i >= n - k && i >= 0  >= 0; i--)
        {
            res -= arr[i];
            
            if(i-x>=0){
                sum-=arr[i-x];
                res+=arr[i-x];
            }


            answer = max(answer, sum - res);
        }

        cout << answer << endl;
        //cout<<"-------"<<endl;
    }

    return 0;
}