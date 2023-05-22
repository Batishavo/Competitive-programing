#include <bits/stdc++.h>

using namespace std;

int n,
    arr[20];

bool flag=false;

stack<string>ans;

void dp(int pos, int tomado, string cad)
{

    if (tomado == 6)
    {
        ans.push(cad);
        return;
    }
    if (pos >= n)
    {
        return;
    }
    dp(pos + 1, tomado, cad);
    if(cad==""){
    dp(pos + 1, tomado + 1, cad + to_string(arr[pos]));
    }
    else{
        dp(pos + 1, tomado + 1,cad +" "+ to_string(arr[pos]));
    }
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    while (scanf("%d", &n))
    {

        if (n == 0)
            break;
        if(flag){
            printf("\n");
        }
        else{
            flag = true;
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        dp(0, 0, "");

        while(!ans.empty()){
            cout<<ans.top()<<endl;
            ans.pop();
        }
    }

    return 0;
}