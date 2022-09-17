// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        // Code here
        sort(arr.begin(),arr.end());
        int mayor=arr[0];
        for(int i=1;i<arr.size();i++){

            int aux=arr[i];

            if(mayor==1){
                break;
            }
            while(aux!=0){

                if(aux%mayor==0){
                    break;
                }
                else{
                    int tmp=mayor;
                    mayor=aux%mayor;
                    aux=tmp;
                }

            }


        }

        return mayor;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}  // } Driver Code Ends
