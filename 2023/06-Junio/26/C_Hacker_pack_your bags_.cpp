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

int binary_search(){

}

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

    


    printf("%lld\n",answer);

    return 0;
}