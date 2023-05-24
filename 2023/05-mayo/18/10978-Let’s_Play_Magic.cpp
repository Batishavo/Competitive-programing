#include <bits/stdc++.h>

using namespace std;

int n,
    sum;

string arr[60],
    cad,
    pos;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    while (scanf("%d", &n))
    {
        if (n == 0)
        {
            break;
        }
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> cad >> pos;
            for(int j=0;j<pos.size(); j++){
                sum++;
                sum%=n;
                
                if(arr[sum]!=""){
                    j--;
                }

            }
            arr[sum]=cad;
        }
        for (int i = 1; i < n; i++)
        {
            cout << arr[i];
            cout<<" ";
            arr[i]="";
        }
        cout<<arr[0];
        cout << endl;
        arr[0]="";
    }

    return 0;
}