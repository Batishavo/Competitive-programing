#include <bits/stdc++.h>

using namespace std;

int n,
    query,
    memo[110][10];
char digit[10] = {'i', 'v', 'x', 'l', 'c'};

void roman_digit(int pos)
{
    int aux=pos;
    for (int i = 0; i < 5; i++)
    {
        memo[pos][i] = memo[pos - 1][i];
    }
    if(aux/100>0){
        memo[pos][4]++;
        aux-=100;
    }
    if(aux/90>0){
        memo[pos][4]++;
        memo[pos][2]++;
        aux-=90;
    }
    if(aux/50>0){
        memo[pos][3]++;
        aux-=50;
    }
    if(aux/40>0){
        memo[pos][3]++;
        memo[pos][2]++;
        aux-=40;
    }
    if(aux/10>0){
        memo[pos][2]+=aux/10;
        aux%=10;
    }
    if(aux/9>0){
        memo[pos][2]++;
        memo[pos][0]++;
        aux-=9;
    }
    if(aux/5>0){
        memo[pos][1]++;
        aux-=5;
    }
    if(aux/4>0){
        memo[pos][1]++;
        memo[pos][0]++;
        aux-=4;
    }
    if(aux>0){
        memo[pos][0]+=aux;
    }
    
}

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    for (int i = 1; i <= 100; i++)
    {
        roman_digit(i);
    }

    while (cin >> n)
    {
        if(n==0){
            break;
        }
        cout << n << ": ";
        for (int i = 0; i < 5; i++)
        {
            if (i == 4)
            {
                cout << memo[n][i] << " " << digit[i] << endl;
            }
            else
            {
                cout << memo[n][i] << " " << digit[i] << ", ";
            }
        }
    }

    return 0;
}