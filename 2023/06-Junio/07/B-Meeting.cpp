#include<bits/stdc++.h>

using namespace std;

const int limit = 10e3+10;

int x[5],
    y[5],
    radiators[limit][5],
    r,
    answer;


bool distance(int x1,int y1,int x2,int y2,int distance){

    double d_distance = (double)distance;
    
    double distance_between=sqrt((double)pow(x1-x2,2) + (double)pow(y1-y2,2));

    //cout<<" "<<distance_between<<" "<<distance<<endl;

    return distance_between<=d_distance;
}

bool need_blanket(int x,int y){

    for(int i=0;i<r;i++){
        if(distance(x,y,radiators[i][0],radiators[i][1],radiators[i][2])){
            return 0;
        }
    }
    return 1;
}

int sumatoria_x(int ini,int fin,int p){

    //cout<<"entra";

    int cont= 0;

    for(int i=ini;i<=fin;i++){

        //cout<<i<<" "<<p;

        cont+=need_blanket(i,p);
    }

    return cont;
}


int sumatoria_y(int ini,int fin,int p){
    //cout<<"entra"<<endl;
    int cont= 0;

    for(int i=ini;i<=fin;i++){
        //cout<<p<<" "<<i;
        cont+=need_blanket(p,i);
    }

    return cont;

}

int main(){

    for(int i=0;i<2;i++){
        cin>>x[i]>>y[i];
    }

    cin>>r;

    for(int i=0;i<r;i++){
        
        cin>>radiators[i][0]
           >>radiators[i][1]
           >>radiators[i][2];
    
    }

    //cout<<"_______"<<endl;

    answer+=sumatoria_x(min(x[0],x[1])  ,max(x[1],x[0]),y[0]);
    answer+=sumatoria_x(min(x[0],x[1])  ,max(x[1],x[0]),y[1]);
    answer+=sumatoria_y(min(y[0],y[1])+1,max(y[0],y[1])-1,x[0]);
    answer+=sumatoria_y(min(y[0],y[1])+1,max(y[0],y[1])-1,x[1]);

    printf("%d\n", answer);

    return 0;
}