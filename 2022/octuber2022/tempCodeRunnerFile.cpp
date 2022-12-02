#include<bits/stdc++.h>

using namespace std;

int vp,
    vd,
    t,
    f,
    c,
    cont=0,
    pd=0,
    pp=0,
    flag = 1,
    tmp;

int main(){

    cin>>vp>>vd>>t>>f>>c;

   for(int i=1;;i++){
        pp+=vp;
        if(pp>=c){
            break;
        }
        if(i<=t){
            continue;
        }
        /////////////
        if(flag==1){
            pd+=vd;
            if(pd>=pp){
                //printf("--%d\n",i);
                cont++;
                flag=0;
                //pd==pp;
            }
        }
        else if(flag==0){
            pd-=vd;
            if(pd<=0){
                tmp=f-1;
                flag=2;
                //pd=1;
            }
        }
        else if(flag==2){
            tmp--;
            if(tmp<=0){
                flag=1;
            }
        }


   }

    cout<<cont<<endl;

    return 0;
}