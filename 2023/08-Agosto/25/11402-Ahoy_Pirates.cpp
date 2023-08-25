#include<bits/stdc++.h>

using namespace std;

const int limit = 1e5;

struct pirates
{
    int buccaneer;
    int barbary;

    pirates(int buccaneer,int barbary ){
        this->buccaneer = buccaneer;
        this->barbary = barbary;
    }
};

pirates segment_tree[4+limit];

pirates sum_pirats(pirates a,pirates b){
    return pirates(a.buccaneer+b.buccaneer,a.barbary+b.barbary);
}

void build(int node,int start,int fin,string island){

    if(start==fin){

        int buccanneer=0;
        int barbary=0;

        if(island[start]=='1'){
            buccanneer = 1;
        }
        else{
            barbary=1;
        }

        segment_tree[node] = pirates(buccanneer,barbary);
        return;
    }

    int mid = (start+fin)/2;
    build(node*2,start,mid,island);
    build(node*2+1,mid+1,fin,island);
    segment_tree[node] = sum_pirats(segment_tree[2*node],segment_tree[2*node+1]);
}

int seg_query(int node,int start,int fin,int l,int r){

    if(r<start || l>fin){
        return 0;
    }
    if(l<=start && fin>=fin){
        return segment_tree[node].buccaneer;
    }

    int mid = (start+fin)/2;
    int left_sum = seg_query(2*node,start,mid,l,r);
    int right_sum = seg_query(2*node+1,mid+1,fin,l,r);

    return left_sum+right_sum;

}

void update(int node ,int start,int fin,int tipe){

    if(start==fin){
        return;
    }
    int mid = (start+fin)/2;
    if(index<=mid){
        update(2*node,start,mid,index);
    }
    else{
        update(2*node+1,mid+1,fin,index);
    }
    
    segment_tree[node] = sum_pirats(segment_tree[2*node],segment_tree[2*node+1]);

}

void update_F(){

}
void update_E(){
    
}
void update_I(){
    
}

int main(){

    int test;
    int n;
    int m;
    int query;
    int pos = 0;

    string island;
    string part_island;

    scanf( "%d",&test);
    
    while(test--){
        
        printf("Case %d:\n",++pos);

        island="";

        cin>>n;

        for(int i=0;i<n;i++){
            cin>>m>>part_island;
            for(int i=0;i<m;i++){
                island+=part_island;
            }
        }

        build(1,0,island.size()-1,island);

        cin>>query;
        
        int num=0;

        while(query--){
            
            char type;
            int a;
            int b;
            
            cin>>type>>a>>b;

            if(type=='S'){
                printf("Q%d: %d\n",++num,seg_query(1,0,island.size()-1,a,b));
            }
            else if(type=='F'){
                update_F(1,0,island.size()-1,l,r);
            }
            else if(type=='E'){
                update_E(1,0,island.size()-1,l,r);
            }
            else {
                update_I(1,0,island.size()-1,l,r);
            }


        }

    }

    return 0;
}