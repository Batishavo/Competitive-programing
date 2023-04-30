#include <bits/stdc++.h>

using namespace std;

int n,
    m,
    memo[105],
    answersize;

string cads[105],
    cadL,
    cadR,
    answerCad;

bool equal(string first, string second)
{
    int pos = m;
    for (int i = 0; i < m; i++)
    {
        if (first[i] != second[--pos])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> cads[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (memo[i] == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (i!=j && memo[j] == 0 && equal(cads[i], cads[j]))
                {
                    memo[i] = 1;
                    memo[j] = 1;
                    cadL += cads[i];
                    string aux=cadR;
                    cadR = cads[j]+aux;
                }
            }
        }
    }

    answersize=cadL.size()*2;
    answerCad=cadL+cadR;

    for(int i = 0; i < n; i++){
        if(memo[i] == 0){
            string aux = cads[i];
            reverse(cads[i].begin(), cads[i].end());
            if(aux==cads[i]){
                answersize+=m;
                answerCad=cadL+aux+cadR;
                break;
            }
        }
    }
    cout<<answersize<<endl<<answerCad<<endl;
    return 0;
}