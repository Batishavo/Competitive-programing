#include<bits/stdc++.h>

using namespace std;

string cad,
       cad2;

int total,
    cant;

bool comp(string posibility){

    int mas=0,
        menos=0;

    for(int i=0;i<cad.size();i++){
        if(cad[i]=='+'){
            mas++;
        }
        else{
            menos++;
        }
        ///////////////////////
        if(posibility[i]=='+'){
            mas--;
        }
        else{
            menos--;
        }

    }

    return mas==0 && menos ==0;

}

void calculos(string cambio,int pos){

    if(pos==cad.length()){

        total++;

        if(comp(cambio)){
            cant++;
        }

        return;
    }

    if(cambio[pos]=='?'){

        cambio[pos]='+';
        calculos(cambio,pos+1);

        cambio[pos]='-';
        calculos(cambio,pos+1);

    }
    else{
        calculos(cambio,pos+1);
    }


}

int main(){

    cin>>cad>>cad2;

    calculos(cad2,0);

   // printf("%d %d\n",total,cant);

    if(total!=0 && cant!=0){
        double dividendo=(double)cant,
                divisor=(double)total;
        printf("%0.12f\n",dividendo/divisor);
    }
    else{
        printf("0.000000000000\n");
    }



    return 0;
}
