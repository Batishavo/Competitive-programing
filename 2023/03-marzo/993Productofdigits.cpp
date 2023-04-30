#include <bits/stdc++.h>

using namespace std;

int t;

string dp(int n, string num)
{

    if (n == 1)
    {
        if(num==""){
            num="1";
        }
        sort(num.begin(), num.end());
        return num;
    }
    for (int i = 9; i >= 2; i--)
    {
        if (n % i == 0)
        {
            return dp(n / i, num + to_string(i));
            //cout<<"-----"<<endl;
        }
    }
    return "-1";
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {
        int n;
        cin >> n;
        if(n==0){
            cout<<"0"<<endl;
            continue;
        }
        cout << dp(n, "")<<endl;
    }

    return 0;
}