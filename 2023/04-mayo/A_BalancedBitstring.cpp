#include <bits/stdc++.h>

using namespace std;

const int limit=30e5+10;

int t,
    n,
    k,
    memo[limit];

string cad;

void marks(){
    for(int i=0;i<n;i++){
        if(cad[i]!='?' && memo[i]==0){
            for(int j=i;j<n;j+=k){
                memo[j] =1;
                if(cad[j]=='?'){
                    cad[j] = cad[i];
                }
            }
            for(int j=i;j>=0;j-=k){
                memo[j] =1;
                if(cad[j]=='?'){
                    cad[j] = cad[i];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        memo[i] =0;
    }
}

bool balaced()
{
    int ones = 0,
        ceros = 0;

    for (int i = 0; i < k; i++)
    {
        if (cad[i] == '1')
        {
            ones++;
        }
        else if (cad[i] == '0')
        {
            ceros++;
        }
    }
    if (ones > k / 2 || ceros > k / 2)
    {
        return false;
    }
    for (int i = k; i < n; i++)
    {
        if (cad[i - k] == '1')
        {
            ones--;
        }
        else if (cad[i - k] == '0')
        {
            ceros--;
        }

        if (cad[i] == '1')
        {
            ones++;
        }
        else if (cad[i] == '0')
        {
            ceros++;
        }
        if (ones > k / 2 || ceros > k / 2)
        {
            return false;
        }
    }
    return true;
}

bool patron()
{
    for (int i = 0; i < k; i++)
    {
        int pos = i;
        int num = -1;
        while (pos < n)
        {
            if (cad[pos] == '1')
            {
                if (num == -1)
                {
                    num = 1;
                }
                else
                {
                    if (num != 1)
                    {
                        return false;
                    }
                }
            }
            else if (cad[pos] == '0')
            {
                if (num == -1)
                {
                    num = 0;
                }
                else
                {
                    if (num != 0)
                    {
                        return false;
                    }
                }
            }
            pos += k;
        }
    }
    return true;
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    scanf("%d", &t);

    while (t--)
    {

        cin >> n >> k >> cad;
        marks();
        if (balaced() && patron())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}