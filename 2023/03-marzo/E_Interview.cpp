#include <bits/stdc++.h>
#include <cstring>

using namespace std;

const int limi = 20e5 + 10;

int t,
    n,
    sum = 0,
    aux,
    arr[limi];

bool constains(int ini, int fin)
{   
    printf("? %d ",fin-ini+1);
    for(int i=ini;i<=fin;i++){
        printf("%d ",i);
    }
    fflush(stdout);
    int res;
    scanf("%d", &res);
    int sum = arr[fin]-arr[ini-1];
    return sum!=res;
}

int binary_search()
{
    int ini = 1,
        fin = n;

    bool flag=0;

    while (ini < fin)
    {

        int mid = ini + ((fin - ini) / 2);
        
        int l,r;

        if(flag){
            l=mid;
            r=fin;
        }
        else{
            l=ini;
            r=mid;
        }

        bool can=constains(l,r);
        if(can){
            flag=0;
            fin=mid;
        }
        else{
            flag=1;
            ini=mid+1;
        }
    }
    return ini;
}

int main()
{
    scanf("%d", &t);

    while (t--)
    {
        sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> aux;
            sum += aux;
            arr[i] = sum;
        }
        int res = binary_search();
        cout << "! " << res << endl;
        fflush(stdout);
    }
    return 0;
}