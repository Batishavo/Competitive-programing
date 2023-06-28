#include<bits/stdc++.h>

using namespace std;

const int limit = 20e5+10;

struct voucher{
    int l,
        r,
        num;
    
    long long cost;
    voucher(){
        l=0;
        r=0;
        cost=0;
        num=0;
    }

    voucher(int l, int r,long long cost, int num){
        this->l=l;
        this->r=r;
        this->cost=cost;
        this->num=num;
    }

};

int n,
    x;

long long answer=-1;

voucher arr[limit];

vector<voucher>order_l[limit],
    order_r[limit];

vector<long long>better_l[limit],
    better_r[limit];

bool sort_l(voucher a, voucher b){

    if(a.l==b.l){
        return a.r<b.r;
    }

    return a.l<b.l;

}

bool sort_r(voucher a, voucher b){
    if(a.r==b.r){
        return a.l<b.l;
    }
    return a.r<b.r;
}

void fill_beters(){
    //fill better l
    for(int i=0;i<limit;i++){
        if(order_l[i].size()>0){
            better_l[i].push_back(order_l[i][0].cost);
            for(int j=1;j<order_l[i].size();j++){
                better_l[i].push_back(min(better_l[i][j-1],order_l[i][j].cost));
            }
        }
    }
    //fill better r
    for(int i=0;i<limit;i++){
        int tam = order_r[i].size(); 
        if(tam>0){
            for(int j=0;j<tam;j++){
                better_r[i].push_back(0);
            }
            better_r[i][tam-1]=order_r[i][tam-1].cost;
            for(int j=tam-2;j>=0;j--){
                better_r[i][j]=min(better_r[i][j+1],order_r[i][j].cost);
            }
        }
    }
}

int binary_search_l(int pos,int l){
    int ini = 0,
        fin =  order_l[pos].size();
    
    while(ini<fin){
        int mid = (ini+mid)/2+1;
        if(order_l[pos][mid].r>l){
            fin=mid-1;
        }
        else{
            ini = mid;
        }
    }
    return fin;

}

int binary_search_r(int pos,int l){

    int ini = 0,
        fin = order_r[pos].size();

    while(ini<fin){
        int mid = ini +(fin-ini)/2;

        if(order_r[pos][mid].r<l){
            ini;
        }
        else{
            fin;
        }
    }
    return ini;
}

int main(){

    scanf("%d %d",&n,&x);

    for(int i=0; i<n; i++){
        scanf("%d %d %lld",&arr[i].l,&arr[i].r,&arr[i].cost);
        arr[i].num=arr[i].r-arr[i].l+1;
        order_r[arr[i].num].push_back(arr[i]);
        order_l[arr[i].num].push_back(arr[i]);
    }

    for(int i=0;i<limit;i++){
        sort(order_r[i].begin(),order_r[i].end(),sort_r);
        sort(order_l[i].begin(),order_l[i].end(),sort_l);
    }

    fill_beters();

    for(int i=0;i<n;i++){
        int pos = x-arr[i].num;
        if(arr[i].num<x && order_r[pos].size()>0){
            
            int pos_l=binary_search_l(pos,arr[i].l),
                pos_r=binary_search_r(pos,arr[i].l);
            
            long long sum=0;

            if(pos_l==-1 && pos_r==-1){
                continue;
            }
            else if(pos_l==-1){
                sum=better_r[pos][pos_r];
            }
            else if(pos_r==-1){
                sum=better_l[pos][pos_l];
            }
            else{
                sum=min(better_l[pos][pos_l],better_r[pos][pos_r]);
            }
            
            if(answer==-1){
                answer=arr[i].cost+sum;
            }
            else{
                answer=min(answer,arr[i].cost+sum);
            }
        }
    }

    printf("%lld\n",answer);

    return 0;
}