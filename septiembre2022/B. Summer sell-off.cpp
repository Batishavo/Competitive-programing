#include<bits/stdc++.h>

using namespace std;

struct ventas{

    long long c;
    long long p;
    long long d;
};

ventas aux;

int n,m;

long long client,product,cont=0;

vector<ventas>days;

bool mayor(ventas a,ventas b){
    return a.d>b.d;
}

sumar(){

    /*printf("---");
    for(int i=0;i<days.size();i++){
        printf("%d %d\n",days[i].first,days[i].second);
    }*/
    int num=days.size();
    for(int i=0;i<min(num,m);i++){
        cont+=days[i].d+days[i].p;
    }
    for(int i=m;i<days.size();i++){
        cont+=min(days[i].c,days[i].p);
    }

}

int main(){

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        scanf("%lld %lld",&product,&client);

        if(client<=product){
            cont+=client;
        }
        else{
            aux.p=product;
            aux.c=client;
            /////
            if(product*2<=client){
                aux.d=product;
            }
            else{
                aux.d=client-product;
            }

            days.push_back(aux);
        }
    }
    sort(days.begin(),days.end(),mayor);

    sumar();

    printf("%lld\n",cont);


    return 0;
}
