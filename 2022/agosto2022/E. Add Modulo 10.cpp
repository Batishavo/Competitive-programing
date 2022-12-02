#include<bits/stdc++.h>

using namespace std;

const int limit = 20e5+10;

int t,
    n,
    aux,
    arr[limit];

bool flag,
     flag0,
     flag5;

bool num(int arr_i,int arr_j){

    while(arr_i%10!=6){

        arr_i+=arr_i%10;

    }
    while(arr_j%10!=6){

        arr_j+=arr_j%10;
    }

    int num1=(arr_i-(arr_i%10))/2,
        num2=(arr_j-(arr_j%10))/2;


    return num1%2==num2%2;
}

bool flag5_0(){

    bool newFlag = true;

    int comp;

    if(arr[0]%10==0){

        comp = arr[0];

    }
    else if(arr[0]%10==5){
        comp = arr[0]+(arr[0]%10);
    }
    else{
        return false;
    }

    for(int i=1;i<n;i++){


        if(arr[i] == arr[i-1]){
            continue;
        }
        else if(arr[i]%10==0 ){

            //cout<<"1"<<endl;
            if(arr[i]!=comp) return false;

        }
        else if(arr[i]%10==5){

            //cout<<"2"<<endl;
            int aux = arr[i]+(arr[i]%10);

            if(comp!=aux){
                return false;
            }
        }
        else{
            //cout<<"3"<<endl;
            return false;
        }

    }

    return newFlag;
}

int main(){

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        flag  = true;
        flag0 = false;
        flag5 = false;

        for(int i=0;i<n;i++){

            scanf("%d",&arr[i]);

            if(arr[i]%10==0){
                flag0 = true;
            }
            else if(arr[i]%10==5){
                flag5 = true;
            }


        }
        if(flag0 || flag5){

            //printf("X");
            flag = flag5_0();

        }
        else{
            for(int i=0;i<n-1;i++){

                flag = num(arr[i],arr[i+1]);

                if(!flag)break;
            }
        }

        printf(flag?"YES\n":"NO\n");
    }

    return 0;
}
