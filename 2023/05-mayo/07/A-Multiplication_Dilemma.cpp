#include<bits/stdc++.h>

using namespace std;

const long long limit = 10e9;

long long n,
    m,
    sum;

int t;

vector<long long>Special_Numbers;

map<long long,pair<long long,long long>>memo;

void Create_Special_Numbers(){
    long long num = 1;
    while (num<=limit)
    {
        for(int i=1;i<=9;i++){
            Special_Numbers.push_back(i*num);
            Special_Numbers.push_back(-i*num);
        }
        num*=10;
    }

    for(int i=0;i<Special_Numbers.size();i++){
        for(int j=0;j<Special_Numbers.size();j++){
            long long aux=Special_Numbers[j]*Special_Numbers[i];
            pair<long long,long long>actual={Special_Numbers[j],Special_Numbers[i]};
            memo[aux]=actual;
        }
    }

}


int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    Create_Special_Numbers();
    
    scanf( "%d",&t);
    
    while(t--){
    
        cin>>n>>m;
        sum=n*m;
        for(auto x : memo){
            long long tmp = abs(sum-x.first);
            if(memo.count(tmp)){

                long long num1=x.second.first,
                    num2=x.second.second,
                    num3=memo[tmp].first,
                    num4=memo[tmp].second;
                
                char simbol;

                if((num1*num2) + (num3*num4)==sum){
                    simbol = '+';
                }
                else{
                    simbol = '-';
                }

                printf("%lld x %lld %c %lld x %lld\n",num1,num2,simbol,num3,num4);

                break;
            }
        }
    }

    return 0;
}