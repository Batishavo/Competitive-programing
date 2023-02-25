#include <bits/stdc++.h>

using namespace std;

int t,
    n,
    arr[200];

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        bool flag=0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(__gcd(arr[i],arr[j])<=2){
                    flag=1;
                }
            }
        }
        printf(flag?"YES\n":"NO\n");
    }

    return 0;
}