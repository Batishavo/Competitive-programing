#include<bits/stdc++.h>

using namespace std;

const int limit = (10e6)+10;

int t,n;
string cad;
long long cont;
bool isPrime[limit];
vector<int> primes;

void criba() {
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<limit;i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j=i+i; j<limit; j+=i){
                isPrime[j] = 0;
            }
        }
    }
}

long long suma(int pos){
    if(isPrime[pos]== true){
        return pos;
    }
    for(auto x:primes){
        if(pos%x==0){
            return x;
        }
    }
}

int main(){

    criba();
    cin>> t;
    while(t--){
        cont=0;
        cin>>n>>cad;

        for(int i=0;i<n;i++){

            if(cad[i] == '0'){
                cont+=suma(i+1);
            }


        }

        cout<<cont<<endl;
    }

    return 0;
}
