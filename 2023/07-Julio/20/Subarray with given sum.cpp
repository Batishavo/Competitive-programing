//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        
        int pointer_l=0;
        int pointer_r=0;
        
        long long sum = arr[0];
        
        vector<int> solution;
        
        solution.push_back(-1);
        
        while(pointer_r<n-1){
            if(sum==s){
                break;
            }
            else if(sum<s ){
                pointer_r++;
                sum+=arr[pointer_r];
            }
            else{
                if(pointer_r!=pointer_l){
                    sum-=arr[pointer_l];
                    pointer_l++;
                }
                else{
                    pointer_r++;
                    pointer_l=pointer_r;
                    sum=arr[pointer_r];
                }
            }
        }
        
        while(sum>s && pointer_l<n){
            sum-=arr[pointer_l];
            pointer_l++;
        }
        
        if(sum==s && s!=0){
            solution.push_back(pointer_r+1);
            solution[0]=pointer_l+1;
        }
        
        return solution;
    
        
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends