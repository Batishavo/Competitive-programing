#include<bits/stdc++.h>

using namespace std;

struct DNA{
    string cad;
    int val;

    DNA(){
        cad="";
        val=0;
    }
    DNA(string cad,int val){
        this->cad=cad;
        this->val=val;
    }
};

int t,
    n,
    m;

bool flag = false;

DNA DNA_Cads[110];

int valor(DNA DNA_Valor){
    string tmp =DNA_Valor.cad;
    int sum=0;
    for(int i=0;i<tmp.length();i++){
        for(int j=i+1;j<tmp.length();j++){
            if(tmp[j]<tmp[i]){
                sum++;
            }
        }
    }

    return sum;
}

/*bool order(DNA a, DNA b){
    return a.val<b.val;
}*/

void clean(){
    for(int i=0;i<=100;i++){
        DNA_Cads[i]={"",0};
    }
}

int main(){
    
    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    scanf( "%d",&t);
    
    while(t--){
        
        if(flag){
            cout<<endl;
            clean();
        }
        else{
            flag = true;
        }

        cin>>n>>m;

        for(int i=0;i<m;i++){
            cin>>DNA_Cads[i].cad;
        }

        for(int i=0;i<m;i++){
            DNA_Cads[i].val=valor(DNA_Cads[i]);
        }

        for(int i=0;i<m;i++){
            for(int j=1;j<m;j++){
                if(DNA_Cads[j].val<DNA_Cads[j-1].val){
                    swap(DNA_Cads[j],DNA_Cads[j-1]);
                }
            }
        }

        for(int i=0;i<m;i++){
            cout<<DNA_Cads[i].cad
                // <<" "
                // <<DNA_Cads[i].val
                <<endl;
        }   
    }

    return 0;
}