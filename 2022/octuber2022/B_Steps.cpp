#include<bits/stdc++.h>

using namespace std;

int k;

long long n,m,x,y,cont,xc,yc,px,py;

int main(){

    cin>>n>>m>>x>>y>>k;
    while(k--){
        cin>>xc>>yc;
        
        ////////////////
        if(xc>0){
            px=(n-x)/xc;
        }
        else if(xc==0){
            px=0;
        }
        else{
            px=(x-1)/(xc*-1);
        }

        if(yc>0){
            py=(m-y)/yc;
        }
        else if(yc==0){
            py=0;
        }
        else{
            py=(y-1)/(yc*-1);
        }
        ///////////////////
        if(xc==0){
            cont+=py;
            y+=(yc)*py;
        }
        else if(yc==0){
            cont+=px;
            x+=(xc)*px;
        }
        else{
            cont+=min(px,py);
            x+=(xc)*min(px,py);
            y+=(yc)*min(px,py);
        }
        //printf("cont: %d px:%d py:%d\n",cont,px,py);
    }
    //cout<<x<<" "<<y<<endl;
    cout<<cont<<endl;

    return 0;
}