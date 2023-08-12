#include <bits/stdc++.h>

using namespace std;

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;
    int n;
    int total_mayor=0;

    long long mayor;
    long long arr[110];

    cin >> t;

    while (t--)
    {

        cin>>n;

        mayor = 0;
        total_mayor = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mayor=max(arr[i],mayor);
        }

        for(int i=0;i<n;i++){
            if(arr[i]==mayor){
                total_mayor++;
            }
        }

        if(total_mayor==n){
            cout<<"-1\n";
        }
        else{
            cout<<n-total_mayor<<" "<<total_mayor<<endl;

            for(int i=0;i<n;i++){
                if(arr[i]!=mayor){
                    cout<<arr[i]<<" ";
                }
            }
            cout<<endl;
            for(int i=0;i<total_mayor;i++){
                cout<<mayor<<" ";
            }
            cout<<endl;
        }

    }

    return 0;
}
