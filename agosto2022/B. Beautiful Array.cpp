#include<bits/stdc++.h>

using namespace std;

int n,t;
long long k,b,s;

vector<long long> arr;

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d %lld %lld %lld",&n,&k,&b,&s);

        if(s/k>=b){

            long long aux=(b*k);

            if(s-aux>=k-1){
                aux+=k-1;
            }
            else{
                aux+=s-aux;
            }

            s-=aux;
            arr.push_back(aux);

            for(int i=1;i<n;i++){

                if(s-(k-1)>=0){
                    s-=k-1;
                    arr.push_back(k-1);
                }
                else if(s==0){
                    arr.push_back(0);
                }
                else if(s-(k-1)<0){
                    arr.push_back(s);
                    s=0;
                }

            }

            if(s!=0){
                printf("-1");
            }
            else{
                for(auto x:arr){
                    printf("%lld ",x);
                }
            }

        }
        else{

            printf("-1");

        }
        printf("\n");
        arr.clear();

    }


    return 0;
}
