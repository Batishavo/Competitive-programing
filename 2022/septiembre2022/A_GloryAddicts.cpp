#include <bits/stdc++.h>

using namespace std;

const int limit = (10e5) + 10;

int t,
    n,
    element[limit],
    contF,
    contH,
    menorComp,
    
    pj;

long long cont,
          leer;

vector<long long> menor,
            mayor;

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        scanf("%d", &n);
        
        contF = 0;
        contH = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &element[i]);
            if (element[i] == 0)
            {
                contF++;
            }
            else
            {
                contH++;
            }
        }

        menorComp=(contF<contH)?0:1;

        for (int i = 0; i < n; i++)
        {
            cin>>leer;
            if (element[i] == menorComp)
            {
                menor.push_back(leer);
            }
            else{
                mayor.push_back(leer);
            }
        }

        sort(mayor.begin(),mayor.end());
        sort(menor.begin(),menor.end());
        pj = mayor.size()-1;

        // for(auto x:menor){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:mayor){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // cout<<"--------"<<endl;
        if(menor.size() == mayor.size()){
            for(int i=1;i<menor.size();i++){
                cont+=menor[i]*2;
            }
            for(int i=1;i<mayor.size();i++){
                cont+=mayor[i]*2;
            }
            if(menor[0]>mayor[0]){
                cont+=(menor[0]*2)+(mayor[0]);
            }
            else{
                 cont+=(mayor[0]*2)+(menor[0]);
            }
        }
        else{
            cont+=mayor[0];
            for(int i=0;i<menor.size();i++){
                cont+=menor[i]*2;
                cont+=mayor[pj--]*2;
            }
            // cout<<"**"<<cont<<endl;
            for(int i=pj;i>=1;i--){
                cont+=mayor[i];
            }

        }
        cout<<cont<<endl;
        cont=0;
        menor.clear();
        mayor.clear();
    }

    return 0;
}