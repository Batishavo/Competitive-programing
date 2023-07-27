#include<bits/stdc++.h>

using namespace std;

const int limit=210;

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

int m_Swap(int l,int r,int max_Sum){

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
                    positions_L_R[i].first
                    ,positions_L_R[i].second
                    ,max_Sum
                )
            )
        ;

    }
    
    cout<<answer<<endl;

    return 0;
}