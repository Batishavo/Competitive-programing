#include <bits/stdc++.h>

using namespace std;

int n,
    k,
    memo['z'+10];

string cad;

void mark(){
    for(int i=0; i<cad.length(); i++){
        memo[cad[i]] = 1;
    }
}


int main()
{
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    cin >> n >> k >> cad;
    if (k > n)
    {
        //cout<<"x"<<endl;
        string aux = cad;
        sort(cad.begin(), cad.end());
        while (aux.size() < k)
        {
            aux += cad[0];
        }
        cout<<aux<<endl;
    }
    else{
        mark();
        int flag=1;
        for(int i=k-1;i>=0;i--){
            //cout<<cad[i]<<endl;
            for(int j=cad[i]+1;j<='z';j++){
                if(memo[j]==1){
                    cad[i]=(char)j;
                    flag=0;
                    break;
                }
            }
            if(!flag){
                break;
            }
            else{
                for(int j='a';j<=cad[i];j++){
                    if(memo[j]==1){
                        cad[i]=(char)j;
                        break;
                    }
                }
            }
        }

        for(int i=0; i<k; i++){
            cout<<cad[i];
        }
        cout<<endl;
    }

    return 0;
}