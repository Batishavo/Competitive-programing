#include<bits/stdc++.h>

using namespace std;

int mat[500][500];

void ful_mat(int n){

    for(int i=0;i<n;i++){
        for(int j=n;j<n*2;j++){
            mat[i][j]=mat[i][j-n];
        }
    }
    for(int i=n;i<2*n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=mat[i-n][j];
        }
    }
    
    for(int i=n;i<2*n;i++){
        for(int j=n;j<2*n;j++){
            mat[i][j]=mat[i-n][j-n];
        }
    }

}

int kadane(int arr[],int n){
    
    int max_ending_here=0;
    int max_so_far=INT_MIN;

    for(int i=0;i<n;i++){
        max_ending_here = max(max_ending_here+arr[i],arr[i]);
        max_so_far = max(max_so_far,max_ending_here);
    }
    return max_so_far;
}   

int max_sub_matrix(int n){

    int max_sum = INT_MIN;

    int rows = n;
    int cols = n;

    for(int left=0;left<cols;left++){
        
        int temp[100]={0};

        for(int right=left;right<cols+n;right++){
            for(int i=0;i<rows;i++){
                temp[i] +=mat[i][right];
            }

            int current_sum = kadane(temp,rows);
            max_sum = max(max_sum,current_sum);
        }
    }

    return max_sum;
}

int main(){

    int t;
    int n;

    cin>>t;
    
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }
        ful_mat(n);
        cout<<max_sub_matrix(n)<<endl;
    }

    return 0;
}