#include <bits/stdc++.h>

using namespace std;

int t,
    n,
    aux,
    num_10,
    num_01,
    num_11;

string cad;

int main()
{

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    cin>>t;

    while (t--)
    {

        num_10 = -1;
        num_01 = -1;
        num_11 = -1;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> aux >> cad;
            if (cad == "10")
            {
                if (num_10 == -1)
                {
                    num_10 = aux;
                }
                else
                {
                    num_10=min(num_10, aux);
                }
            }
            else if (cad == "01")
            {
                if (num_01 == -1)
                {
                    num_01 = aux;
                }
                else
                {
                    num_01=min(num_01, aux);
                }
            }
            else if (cad == "11")
            {
                if (num_11 == -1)
                {
                    //cout<<"X"<<endl;
                    num_11 = aux;
                }
                else
                {
                    num_11=min(num_11, aux);
                    //cout<<num_11<<"  "<<aux<<endl;
                }
            }
        }
        if(num_11 ==-1 &&(num_01 == -1 || num_10==-1)){
            cout<<-1<<endl;
        }
        else{
            if(num_11 == -1){
                cout<<num_01+num_10<<endl;
            }
            else if(num_01 == -1 || num_10==-1){
                //cout<<"X";
                cout<<num_11<<endl;
            }
            else {
                cout<<min(num_01+num_10,num_11)<<endl;
            }
        }
    }

    return 0;
}