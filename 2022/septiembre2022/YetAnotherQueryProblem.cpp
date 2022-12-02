// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        int max = *max_element(A.begin(), A.end());
        vector<int>fin(max+5,0),
                   actual(N+5,0),
                   solution;
        
        for(int i=0;i<N;i++){
            fin[A[i]]++;
            actual[i]=fin[A[i]];
        }
        // for(auto x :fin){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x :actual){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<num;i++){
            //cout<<"XXXXX "<<i<<endl;
            int cont=0;
            for(int j=Q[i][0];j<=Q[i][1];j++){
                int aux=fin[A[j]] - actual[j]+1;
                if(aux==Q[i][2]){
                    cont++;
                }
                // cout<<"aux: "<<aux<<" fin: "<<fin[A[j]]
                //     <<" actual: "<<actual[j]<<" cont: "<<cont<<" A[j]: "<<A[j]<<endl;
            }
            solution.push_back(cont);
            
        }
        return solution;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    //cin>>t;
    t=1;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        //cout<<"--------------------------------"<<endl;
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}
  // } Driver Code Ends