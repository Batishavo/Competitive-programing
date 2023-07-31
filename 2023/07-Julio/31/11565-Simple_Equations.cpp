#include<bits/stdc++.h>

using namespace std;

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int t;

    int A;
    int B;
    int C;

    int arr[10];

    bool flag = 0;

    scanf( "%d",&t);
    
    while(t--){
    
        cin>>A>>B>>C;

        flag = 0; 

        for(int i=-sqrt(C);i<=sqrt(C);i++){
            if(flag){
                break;
            }
            for(int j=-sqrt(C);j<=sqrt(C);j++){

                if(flag){
                    break;
                }

                int aux = C - (i*i) - (j*j);

                int aux2 = sqrt(aux);

                if(aux2*aux2 == aux && i+j+aux2==A && i*j*aux2==B && i!=j && i!=aux2 && j!=aux2){
                    flag=1;
                    arr[0]=i;
                    arr[1]=j;
                    arr[2]=aux2;
                    break;
                }

            }
        }

        if(!flag){
            cout<<"No solution."<<endl;
        }
        else{
            //sort(arr,arr+3);
            // printf("%d %d %d\n",A,B,C);
            // printf("%d %d %d\n",arr[0]+arr[1]+arr[2],arr[0]*arr[1]*arr[2],(arr[0]*arr[0])+(arr[1]*arr[1])+(arr[2]*arr[2]));
            // printf("%d %d %d\n",arr[0],arr[1],arr[2]);
             sort(arr,arr+3);
             printf("%d %d %d\n",arr[0],arr[1],arr[2]);

            //printf("%d\n",(-6*-6)+(-6*-6)+(-30*-30));
        }

    }

    return 0;
}