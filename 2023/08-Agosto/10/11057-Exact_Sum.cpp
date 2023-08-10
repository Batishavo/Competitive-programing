#include<bits/stdc++.h>

using namespace std;

const int limit = 10e4+10;

long long bynary_search(int ini, int fin,long long arr[],long long num_search){

    //cout<<num_search<<" ";

    if(ini==fin && arr[ini]==num_search){
        return num_search;
    }

    while(ini<fin){
        
        int mid = ((ini+fin)/2)+1;
        
        //cout<<mid<<endl;

        if(arr[mid]==num_search){
            //cout<<"existe"<<endl;
            return num_search;
        }
        else if(arr[mid]>num_search){
            fin=mid-1;
        }
        else{
            ini=mid;
        }

    }
    //cout<<"NO existe"<<endl;
    return -1;
}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    int n;
    
    long long k;
    long long answer_i;
    long long answer_j;

    long long arr[limit];

    //bool flag = true;


    while (cin>>n)
    {
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        cin>>k;

        /*if(flag){
            flag=false;
        }
        else{
            cout<<endl<<endl;
        }*/

        sort(arr,arr+n);

        answer_i=-1;
        answer_j=-1;

        for(int i=0;i<n-1;i++){
            /*if(k-arr[i]<arr[i]){
                break;
            }*/

            long long num = k-arr[i];
            //long long tmp = 1;
            //cout<<arr[i]<<" ";
            long long tmp = bynary_search(i,n-1,arr,num);

            if(answer_i==-1 && tmp!=-1){
                answer_i = arr[i];
                answer_j = tmp;
            }

            if( tmp!=-1 && abs(arr[i]-tmp)<abs(answer_i-answer_j)){
                answer_i = arr[i];
                answer_j = tmp;
            }

        }

        printf("Peter should buy books whose prices are %lld and %lld.\n\n",answer_i,answer_j);
    }
    

    return 0;
}