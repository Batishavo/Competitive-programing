#include <bits/stdc++.h>

using namespace std;

const long long limit = 10e16;

int t,
    n,
    m;

long long aux;

vector<long long> v;

bool posible(long long mid){
    int cont=1,
        ant=v[0];

    for(int i=1;i<n;i++){
        if(v[i]-ant>=mid){
            cont++;
            ant=v[i];
        }
        if(cont>=m){
            break;
        }
    }
    //cout<<cont<<endl;
    return cont>=m;
}

long long binary_search(){

    long long ini=0,
        fin=limit;

    while(ini<fin){

        long long mid=(ini+fin)/2+1;

        if(!posible(mid)){
            fin=mid-1;
        }
        else{
            ini=mid;
        }
        //printf("%lld %d\n",mid,posible(mid));
    }

    return ini;
}

int main()
{

    scanf("%d", &t);

    while (t--)
    {

        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            v.push_back(aux);
        }
        sort(v.begin(), v.end());
        cout<<binary_search()<<endl;
        v.clear();
    }

    return 0;
}