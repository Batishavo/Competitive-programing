#include <bits/stdc++.h>

using namespace std;

int t,
    n,
    m;

bool flag=1;

void wave()
{
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    scanf("%d", &t);

    while (t--)
    {

        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            if(flag==1){
                flag=0;
            }
            else{
                cout << endl;
            }
            wave();
        }
    }

    return 0;
}