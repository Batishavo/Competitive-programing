
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int mayor=0;
        vector<int>memo(n+10,-1);
        queue<pair<int,int>>myqueue;
        myqueue.push({0,0});
        memo[0]=0;
        while(!myqueue.empty()){

            pair<int,int>actual = myqueue.front();
            myqueue.pop();

            int pos=actual.first,
                pasos=actual.second;

            if(pos+arr[pos]>mayor){
                    printf("--%d %d\n",pos,pos+arr[pos]);
                mayor=pos+arr[pos];
                if(mayor>=n-1){
                    return pasos+1;
                }
                for(int i = mayor;i>=0;i--){
                    if(memo[i]!=-1){
                        printf("%d %d\n",i,mayor);
                        break;
                    }
                    printf("X");
                    memo[i]=pasos+1;
                    myqueue.push({i,pasos+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            printf("%d ",memo[i]);
        }
        printf("\n");
        return memo[n-1];

    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
