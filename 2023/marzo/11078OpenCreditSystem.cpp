#include <bits/stdc++.h>

using namespace std;

const int limit = 10e6 + 10;

int arr[limit],
    bucket[limit],
    t,
    n,
    menor,
    mayor;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    
    scanf("%d", &t);

    while (t--)
    {

        cin >> n;

        menor = INT_MAX;
        mayor = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = n - 1; i >= 1; i--)
        {
            menor=min(arr[i],menor);
            bucket[i-1]=menor;
        }
        for(int i = 0; i < n-1; i++){
            
            mayor=max(mayor,arr[i]-bucket[i]);
        }
        cout<<mayor<<endl;
    }

    return 0;
}