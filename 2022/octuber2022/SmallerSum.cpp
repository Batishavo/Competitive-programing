// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<pair<int,long long>> suma;
    
    long long 
        binarySearch(
            int ini,
            int fin,
            int comp
        )
    {
        
        while(ini<fin){
            
            int mid=((ini+fin)/2)+1;
            
            if(suma[mid].first<comp){
                ini=mid;
            }
            else{
                fin=mid-1;
            }
            
        }
        return ini;
        
    }
    
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        suma.clear();
        vector<int>aux = arr;
        vector<long long> res;
        
        long long total=0,
                  actual;
        
        sort(aux.begin(),aux.end());
        suma.push_back({0,0});
        for(int i=0;i<n;i++){
            total+=aux[i];
            suma.push_back({aux[i],total});
        }
        for(int i=0;i<n;i++){
            actual=binarySearch(0,n,arr[i]);
            res.push_back(suma[actual].second);
        }
        return res;
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}  // } Driver Code Ends