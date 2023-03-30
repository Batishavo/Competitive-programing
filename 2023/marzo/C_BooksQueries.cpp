#include <bits/stdc++.h>

using namespace std;

const int limit = 20e5 + 10;

int q,
    l,
    r,
    pos[limit],
    val;

char indice[limit],
    tmp;

int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    scanf("%d", &q);
    scanf(" %c ", &tmp);
    scanf("%d ", &val);
    indice[val] = 'X';
    q--;
    while (q--)
    {

        scanf(" %c ", &tmp);
        scanf("%d", &val);
        //cout<<"**"<<tmp<<endl;
        if (tmp == 'L')
        {
            //cout<<1<<endl;
            pos[val] = ++l;
            indice[val] = 'L';
        }
        else if (tmp == 'R')
        {
            //cout<<2<<endl;
            pos[val] = ++r;
            indice[val] = 'R';
        }
        else
        {
            //cout<<indice[val]<<endl;
            //cout<<indice[val]<<" "<<tmp<<endl;
            /*for(int i=1; i<=5; i++){
                cout<<indice[i]<<" "<<pos[i]<<endl;
            }*/
            //cout << "--" << tmp << endl;
            //cout<<"---"<<endl;
            if (indice[val] == 'L')
            {
                //cout<<"L"<<endl;
                printf("%d\n", min(l - pos[val], r + pos[val]));
            }
            else if(indice[val] == 'R')
            {
                //cout<<"R"<<endl;
                printf("%d\n", min(r - pos[val], l + pos[val]));
            }
            else{
                //cout<<"X"<<endl;
                printf("%d\n",min(l,r));
            }
        }
    }

    return 0;
}