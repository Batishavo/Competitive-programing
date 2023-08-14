/*
    Author : Batishavo
    problem name: 11413 k- Fill the Containers
    plataform: Uva
    Problem_lin: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2408
*/

#include<bits/stdc++.h>

using namespace std;

const long long binary_search_limit=10e12;
const int array_limt=10e6+10;

long long vesels[array_limt];

/*
    boolean lineal method to know if is posible with n vesels
*/
bool is_posble_whit_num_vesels
    (
        long long num
        ,long long m
        ,long long n
    )
{
    long long cont=0;
    long long sum=0;

    for(int i=0;i<n;i++){
        if(vesels[i]>num){
            return false;
        }
        if(sum+vesels[i]>num){
            sum=vesels[i];
            cont++;
        }
        else{
            sum+=vesels[i];
        }
        if(cont>=m){
            return false;
        }
    }
    return true;
}

/*
    binary search to find the maxim of vessels
*/
long long get_max_vesel
    (
        long long m
        ,long long n
    )
{

    long long ini = 0;
    long long fin = binary_search_limit;

    while(ini<fin){

        long long mid = ini +(fin-ini)/2;

        if(is_posble_whit_num_vesels(mid,m,n)){
            fin=mid;
        }
        else{
            ini=mid+1;
        }

    }

    return fin;

}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    int m;

    while(cin>>n>>m){
        
        for(int i=0;i<n;i++){
            cin>>vesels[i];
        }

        cout<< get_max_vesel(m,n)<<endl;
    }

    return 0;
}