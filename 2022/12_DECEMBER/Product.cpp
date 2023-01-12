#include<bits/stdc++.h>

using namespace std;

const int fin=505;

int mat[510][260];

string num1,num2;

void llenado(int litle,int big,string l,string b){

    int acumulado=0,
        r1=0,
        r2=0;

    for(int i=litle-1;i>=0;i--){
        r1++;
        r2=0;
        for(int j=big-1;j>=0;j--){
            r2++;
            int sum= ((l[i]-'0')*(b[j]-'0')+acumulado);
            mat[r1-1][fin-r1-r2+2]=sum%10;
            acumulado=sum/10;
            printf("acumulado: %d\n",acumulado);
            //printf("sum: %d \n",sum);
        }
        mat[r1-1][fin-r1+1-big]=acumulado;
        cout<<"**"<<endl;
    }
}

void llenarMatris(int lonn1,int lonn2){
    if(lonn1<lonn2){
        llenado(lonn1,lonn2,num1,num2);
    }
    else{
        llenado(lonn2,lonn1,num2,num1);
    }
}
void suma(){
    /*cout<<"--------"<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    return "";*/
    for(int i=;i;i){
        for(int j=0;j<;j){

        }
    }
}
void clean(){};

int main(){

    while(true){
        cin>>num1>>num2;
        llenarMatris(num1.size(),num2.size());
        cout<<suma();
        //clean();
    
    }

    return 0;
}