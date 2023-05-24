#include <bits/stdc++.h>

using namespace std;

string cads[1005];

int pos = 0,
    mayor;

void line()
{
    for (int i = 0; i < mayor + 2; i++)
    {
        cout << "*";
    }
    cout << endl;
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    while (getline(cin, cads[pos++]))
    {
        // cout<<cads[pos-1]<<endl;
        mayor = max(mayor, int(cads[pos - 1].length()));
    }

    line();
    bool flag=0;
    for (int i = 0; i < pos - 1; i++)
    {
        int num = mayor - cads[i].size(),
            tmp1 = 0,
            tmp2 = 0;

        if(num%2==1){
            if(flag){
                tmp1=1;
            }
            else{
                tmp2=1;
            }
            flag=!flag;
        }

        cout << "*";
        for (int j = 0; j < num / 2+tmp1; j++)
        {
            cout << " ";
        }
        cout << cads[i];
        for (int j = 0; j < num / 2+tmp2; j++)
        {
            cout << " ";
        }
        cout << "*" << endl;
    }

    line();
    return 0;
}