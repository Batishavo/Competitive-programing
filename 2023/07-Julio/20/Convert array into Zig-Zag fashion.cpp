//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        
        int pointer_l=0;
        int pointer_r=n-1;
        int arr_copy[n+10];    
        int pos = 0;
        bool turn = 1;
        
        while(pointer_l<=pointer_r){
            if(turn){
                arr_copy[pos++]=arr[pointer_l++];
            }
            else{
                arr_copy[pos++]=arr[pointer_r--];
            }
            turn = !turn;
        }
        
        
        for(int i=0;i<n;i++){
            arr[i]=arr_copy[i];
            //cout<<arr[i]<<" ";
        }
        //cout<<endl;
    }
};

//{ Driver Code Starts.

bool isZigzag(int arr[], int n){
    int f=1;
    
    for(int i=1; i<n; i++){
        if(f){
            if(arr[i-1]>arr[i]) return 0;
        }
        else{
            if(arr[i-1]<arr[i]) return 0;
        }
        f=f^1;
    }
    
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        bool check=1;
        check=isZigzag(arr,n);
        
        if(check) cout<<"1\n";
        else cout<<"0\n";
        
    }
    return 0;
}

// } Driver Code Ends