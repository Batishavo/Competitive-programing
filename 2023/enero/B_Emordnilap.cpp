#include <bits/stdc++.h>

using namespace std;
const long long mod = 1000000007;
int t;



long long perm(int n, long long cont)
{
    long long mul=1;
    for(int i=2;i<=n;i++){
        //suma+=cont*i;
        mul=(mul*i%mod);
        //mul%=mod;
    }
    return ((cont%mod)*(mul%mod))%mod;
}

long long solve(int n)
{
    long long cont = 0;
    for (int i = 2; i <= n; i++)
    {
        cont += (i - 1) * 2;
    }
    //printf("%lld \n",cont);
    // return (cont*mul)%mod;
    return perm(n, cont);
}

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        int n;
        cin >> n;
        //cout << "--";
        cout << solve(n) << endl;
    }

    return 0;
}