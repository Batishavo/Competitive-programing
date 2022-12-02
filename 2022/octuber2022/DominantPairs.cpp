// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
         vector<int> di,
                    dj;
        bool flag= true;            
        
        int pi=0,
            pj=0,
            total=0;
                    
        for(int i=0;i<n;i++){
            if(i<n/2){
                di.push_back(arr[i]);
            }
            else{
                dj.push_back(arr[i]);
            }
        }
        
        sort(di.begin(),di.end());
        sort(dj.begin(),dj.end());
        // cout<<"--"<<endl;
        // for(int i=0;i<n/2;i++){

        //     printf("%d %d\n",di[i],dj[i]);

        // }
        // cout<<"--"<<endl;
        while(flag){
            while(di[pi]<dj[pj]*5){
                pi++;
                if(pi>=n/2){
                    flag=false;
                    break;
                }
            }
            printf("pi: %d di: %d\n",pi,di[pi]);
            if(!flag){
                //cout<<"X"<<endl;
                break;
            }
            while(di[pi]>=dj[pj]*5 && pj<n/2){
                pj++;   
            }
            //
            total+=(pj);
            printf("pj: %d dj: %d total: %d ",pj,dj[pj],total);
            //system("pause");
            pi++;
            if(pi>=n/2){
                break;
            }
        }
        
        return total;
    }  
};

// { Driver Code Starts.

int main(){
    int t;
    //cin>>t;
    t=1;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}  // } Driver Code Ends