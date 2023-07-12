#include<bits/stdc++.h>

using namespace std;

struct my_data
{
    
    int my_value
        ,i
        ,j;

    my_data(){
        my_value=0;
        i=0;
        j=0;
    }

    my_data(int my_value,int i,int j){
        this->my_value=my_value;
        this->i=i;
        this->j=j;
    }

};


bool order_j(my_data a,my_data b){
    if(a.j==b.j){
        return a.i<b.i;
    }
    return a.j<b.j;
}

void print_answer(vector<my_data> my_matrix,int m){

    int pos = 0;
    bool flag = false;
    vector<my_data> tmp_data;

    for(int i=1;i<=m;i++){
        
        if(i<my_matrix[pos].j || flag){
            printf("0\n\n");
        }
        else{
            
            tmp_data.clear();
        
            while(pos<my_matrix.size() && my_matrix[pos].j==i){
                tmp_data.push_back(my_matrix[pos]);
                pos++;
            }

            printf("%d",tmp_data.size());

            for(int j=0;j<tmp_data.size();j++){
                printf(" %d",tmp_data[j].i);
            }
            printf("\n");

            for(int j=0;j<tmp_data.size();j++){
                if(j!=0){
                    printf(" ");
                }
                printf("%d",tmp_data[j].my_value);
            }
            printf("\n");

            if(pos>=my_matrix.size()){
                flag = true;
            }
        }

    }

}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n
        ,m;
    
    vector<my_data> my_matrix;

    vector<int>my_pos;

    while(scanf("%d %d",&n,&m)!=EOF){
        
        if(n==0 && m==0){
            break;
        }

        my_matrix.clear();

        for(int i=1;i<=n;i++){
            int pos;
            my_pos.clear();
            scanf("%d",&pos);
            
            for(int j=1;j<=pos;j++){
                int aux;
                scanf("%d",&aux);
                my_pos.push_back(aux);
            }

            for(int j=0;j<pos;j++){
                int aux;
                scanf("%d",&aux);
                my_matrix.push_back({aux,i,my_pos[j]});
            }

        }
        sort(my_matrix.begin(), my_matrix.end(),order_j);
        printf("%d %d\n",m,n);
        print_answer(my_matrix,m);

    }   

    return 0;
}