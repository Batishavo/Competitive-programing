#include<bits/stdc++.h>

using namespace std;

const int limit = 10e3+10;

int n,
    D[limit],
    M[limit],
    Y[limit],
    C[limit],
    cont;

long long total;

bool igual(int i){
    int d=D[i-1],
        m=M[i-1],
        y=Y[i-1];
    if(m==2){
        if(d==28){
            if((y%4==0 && y%100!=0) || (y%400==0)){
                d++;
            }
            else{
                d=1;
                m++;
            }
        }
        else if(d==29){
            d=1;
            m++;
        }
        else{
            d++;
        }
    }
    else if(m==1 || m==3 || m==5 || m==7 || m==8||m==10|| m==12){
        if(m==12){
            if(d==31){
                d=1;
                m=1;
                y++;
            }
            else{
                d++;
            }
        }
        else if(d+1>31){
            d=1;
            m++;
        }
        else{
            d++;
        }
    }
    else{
        if(d+1>30){
            d=1;
            m++;
        }
        else{
            d++;
        }
    }

    return d==D[i] && m == M[i] && y==Y[i];
}

void suma(int i){
    if(igual(i)){
        cont++;
        total+=C[i]-C[i-1];   
    }
}

int main(){
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);
    while(cin>>n){
        if(n==0){
            break;
        }
        total=cont=0;
        bool flag=0;
        for(int i=0;i<n;i++){
            cin>>D[i]>>M[i]>>Y[i]>>C[i];
            if(flag==1){
                suma(i);
            }
            flag=1;
        }
        //cout<<"--";
        cout<<cont<<" "<<total<<endl;
    }

    return 0;
}