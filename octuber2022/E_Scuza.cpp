#include<bits/stdc++.h>

using namespace std;

int t,
    n,
    q,
    cont;

long long maximo, aux,sum,tmp;
vector<long long> solucion;
vector<pair<long long,long long>>numeros;

long long binaSearch(long long comp){

    if(comp < numeros[0].first){
        return 0;
    }
    else if(comp >= numeros[cont-1].first){
        return sum;
    }

    int ini=0,fin=numeros.size()-1;

    while(ini<fin){
        int mid=((ini+fin)/2)+1;
        if(numeros[mid].first>comp){
            fin=mid-1;
        }
        else{
            ini=mid;
        }

    }

    return numeros[fin].second;
    
}


int main(){

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>n>>q;

        for(int i=1;i<=n;i++){
            cin>>aux;
            sum+=aux;
            if(aux>maximo){
                maximo=aux;
                numeros.push_back({aux,sum});
                cont++;
            }
            else{
                numeros[cont-1].second=sum;
            }
        }

        for(int i=0;i<q;i++){
            cin>>aux;
            tmp=binaSearch(aux);
            solucion.push_back(tmp);
        }
        // cout<<"------"<<endl;
        // for(auto x:numeros){
        //     printf("%lld %lld\n",x.first,x.second);
        // }
        //cout<<"------"<<endl;
        for(int i=0;i<q;i++){
            cout<<solucion[i]<<" ";
        }
        cout<<endl; 
        solucion.clear();
        numeros.clear();
        maximo=0;
        cont=0;
        sum=0;
    }

    return 0;
}