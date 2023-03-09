#include<bits/stdc++.h>

using namespace std;

const int limit = 110;

int n,
    m,
    memo[limit],
    answer,
    aux1,
    aux2;

vector<int>vertices[110];

int recorido(int i){
    // cout<<i<<"--";
    int sum=0;
    bool flag=0;
    for(int j=0;j<vertices[i].size();j++){
        if(memo[vertices[i][j]]==0){
            flag=1;
            memo[vertices[i][j]]=1;
            sum+=recorido(vertices[i][j])+1;
        }
    }
    if(!flag){
        // cout<<"entra"<<" "<<i<<endl;
        if(vertices[i].size()==1){
            return 1;
        }
        return 0;
    }
    return sum;
}

int one_vertces(){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(vertices[i].size()==1 && memo[i]==0){
            memo[i]=1;
            sum+=recorido(i);
        }
        else if(vertices[i].size()==0){
            memo[i]=1;
            sum++;
        }
    }
    return sum;
}

int recorido2(int i){
    int sum=0;
    bool flag=0;
    for(int j=0;j<vertices[i].size();j++){
        if(memo[vertices[i][j]]==0){
            flag=1;
            memo[vertices[i][j]]=1;
            sum+=recorido2(vertices[i][j])+1;
        }
    }
    if(!flag){
        // cout<<"entro :"<<i<<enldl;
        return 1;
    }
    return sum;
}

int two_vertces(){
    int sum=0;
    //cout<<"entra"<<endl;
    for(int i=1;i<=n;i++){
        if(memo[i]==0){
            memo[i]=1;
            int aux=recorido2(i);
            // cout<<aux<<endl;
            sum+=(aux%2==0)?aux:aux-1;
        }
    }
    return sum;
}

int main(){

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>aux1>>aux2;
        vertices[aux1].push_back(aux2);
        vertices[aux2].push_back(aux1);
    }
    answer+=one_vertces();
    answer+=two_vertces();
    // cout<<answer<<endl;
    cout<<(n-answer)+((answer)%2)<<endl;
    return 0;
}