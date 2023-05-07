#include <bits/stdc++.h>

using namespace std;

const int limit = 10e7+10;

int t,
    n,
    m;


bool dp(int num){
    if(num==m){
        return 1;
    }
    if(num%3!=0){
        return 0;
    }
    else{
        return dp(num/3)||dp((num/3)*2);
    }
}


int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf("%d", &t);

    while (t--)
    {
        //cout<<t<<endl;

        cin >> n >> m;

        if(dp(n)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }

    return 0;
}