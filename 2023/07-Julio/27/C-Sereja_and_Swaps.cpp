#include<bits/stdc++.h>

using namespace std;

const int limit=210;

int used[limit];

int max_Sum_Sub_Array(int arr[],int n){
    
    int max_sum     = arr[0];
    int current_sum = arr[0];

    for(int i=1;i<n;i++){
        if(current_sum<0){
            current_sum=0;    
        }
        current_sum +=arr[i];
        if(current_sum>max_sum){
            max_sum = current_sum;
        }
    }
    return max_sum;
}

vector<pair<int,int>> get_positions_L_R(int arr[],int n,int max_Sum){

    vector<pair<int,int>> positions_L_R;

    int current_sum = arr[0];
    int l = 0;

    for(int i=1;i<n;i++){
        if(current_sum<0){
            current_sum=0;   
            l=i; 
        }
        current_sum +=arr[i];
        if(current_sum==max_Sum){
            positions_L_R.push_back({l,i});
        }
    }

    return positions_L_R;

}

int get_Mayor(int arr[],int l,int r,int n,int &pos){
    
    int mayor = INT_MIN;
    
    for(int i=r;i<n;i++){
        if(arr[i]>mayor && used[i]==0){
            pos = i;
            mayor = arr[i];
        }
    }

    for(int i = l;i>=0;i--){
        if(arr[i]>mayor && used[i]==0){
            pos = i;
            mayor = arr[i];
        }
    }

    return mayor;
}

int m_Swap(int l,int r,int max_Sum,int k,int arr[],int n){

    while(k!=0 && (l>=0 || r<n)){

        int pos_mayor   = 0;
        int pos_menor   = 0;
        int menor       = 0;
        int mayor       = get_Mayor(arr,l,r,n,pos_mayor);

        for(int i=max(0,l);i<=min(n-1,r);i++){
            
            if(arr[i]<menor && used[i]==0){
                menor     = arr[i];
                pos_menor = i; 
            }
        
        }

        used[pos_menor]=1;

        if(menor<0  && mayor>menor)  {

            max_Sum += mayor+abs(menor);

            used[pos_mayor]=1;
        }
        else{
            if(mayor<=0){
                break;
            }
            if(arr[l]<arr[r]){
                l--;
            }
            /*else if(arr[l]==arr[r]){

            }*/
            else{
                r++;
            }

            max_Sum+=mayor;

        }

        while(l>=0 && arr[l]>=0){
            if(used[l]==0){
                max_Sum+=arr[l];
            }
            l--;
        }
        while(r<n && arr[r]>=0){
            if(used[r]==0){
                max_Sum+=arr[r];
            }
            r++;
        }

        k--;
    }  

    for(int i=0;i<200;i++){
        used[i]=0;
    }

    return max_Sum; 

}

int main(){

    int n;
    int k;
    int max_Sum;
    int answer;

    int arr[limit];

    vector<int>best_K_Numbers;

    vector<pair<int,int>> positions_L_R;

    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    max_Sum       = max_Sum_Sub_Array(arr,n);
    answer        = max_Sum;
    positions_L_R = get_positions_L_R(arr,n,max_Sum);

    for(int i=0;i<positions_L_R.size();i++){

        answer = max(
            answer,m_Swap(
                    positions_L_R[i].first-1
                    ,positions_L_R[i].second+1
                    ,max_Sum
                    ,k
                    ,arr
                    ,n
                )
            )
        ;

    }
    
    cout<<answer<<endl;

    return 0;
}