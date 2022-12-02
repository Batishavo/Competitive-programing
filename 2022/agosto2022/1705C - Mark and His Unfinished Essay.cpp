#include<bits/stdc++.h>

using namespace std;

int t,n,c;

string cad;

long long q,k,l,r;
long long lef[50],
          rig[50],
          diff[50];



int main(){

    cin>>t;

    while(t--){

        cin>>n>>c>>q>>cad;

        lef[0] = 0;
        rig[0] = n;

        for(int i=1;i<=c;++i){
            scanf("%lld %lld",&l,&r);
            l--;
            r--;
            lef[i]=rig[i-1];
            rig[i]=lef[i]+(r-l+1);
            diff[i]=lef[i]-l;
        }
        for(int i=0;i<q;i++){
            scanf("%lld",&k);
            k--;
            for(int i=c;i>=0;--i){
                if(k<lef[i]){
                    continue;
                }
                else{
                    k-=diff[i];
                }
            }
            cout<<cad[k]<<endl;

        }
    }

    return 0;
}
