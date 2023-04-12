#include<bits/stdc++.h>

using namespace std;

int n,
    sum,
    aux,
    query;

int main(){
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    while(cin>>n){
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++){
            cin>>aux;
            sum+=aux;
        }
        printf("Case %d:\n",++query);
        if(abs(sum)%n==0){
            //cout<<sum<<endl;
            cout<<sum/n<<endl;
        }
        else if(sum/n==0){
            int num1=sum%n,
                num2=n;
            cout<<num1<<endl;
            aux=min(num1,num2);
            while(aux>0){
                cout<<"-";
                aux/=10;
            }
            cout<<endl;
            cout<<num2<<endl;
        }
        else{
            int aux=sum/n,
                num1=sum%n,
                num2=n;
            while(aux>0){
                cout<<" ";
                aux/=10;
            }
        
            cout<<num1<<endl;
            cout<<sum/n;
            aux=min(num1,num2);
            while(aux>0){
                cout<<"-";
                aux/=10;
            }
            cout<<endl;
            aux=sum/n;
            while(aux>0){
                cout<<" ";
                aux/=10;
            }
            cout<<num2<<endl;
        }
        sum=0;
    }

    return 0;
}