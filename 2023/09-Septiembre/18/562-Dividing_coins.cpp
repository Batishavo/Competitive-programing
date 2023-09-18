#include<bits/stdc++.h>

using namespace std;

int dividing_coin(int n,vector<int>&nums){
    
    int answer = INT_MAX;
    long long comp = 0;

    //Inicialization of comp

    for(int i=0;i<n;i++){
        comp+=nums[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(comp+1,0));


    //DP

    for(int i=1;i<=n;++i){
        for(int w=1;w<=comp;++w){
            if(nums[i-1]<=w){
                dp[i][w]=max(
                        nums[i-1]
                        +dp[i-1][w-nums[i-1]],dp[i-1][w]
                    )
                ;
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
            int tmp=comp-dp[i][w];
            answer =min(answer,abs(tmp-dp[i][w]));
        }
    }

    return answer;
}


//Gredy solution
// long long dividing_coin(int n,vector<int>&nums){
//     long long p1=0;
//     long long p2=0;

    
//     sort(nums.begin(),nums.end());
//     reverse(nums.begin(),nums.end());
//     for(int i=0;i<n;i++){
//         if(p1<=p2){
//             p1+=nums[i];
//         }
//         else{
//             p2+=nums[i];
//         }
//     }

//     return abs(p1-p2);
// }

int main(){

    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);

    int t;
    int n;
    int num;

    vector<int>nums;


    scanf( "%d",&t);
    
    while(t--){
        
        nums.clear();
        cin>>n;
        
        for(int i=0;i<n;i++){
            cin>>num;
            nums.push_back(num);
        }

        cout<<dividing_coin(n,nums)<<endl;
    }

    return 0;
}