#include<bits/stdc++.h>

using namespace std;


vector<int> calcu_dp
    (
        vector<int>&comp
        ,vector<int>&values
        ,int n
        ,function<bool(int, int)> func
    )
{

    vector<int>dp(n);

    for(int i=0;i<n;i++){
        dp[i]=values[i];
    }

     for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(func(comp[i],comp[j])){
                dp[i]=max(dp[i],dp[j]+values[i]);
            }
        }
    }
    return dp;
}

pair<int,int>dp_increase_decrease
    (
        vector<int> &heights
        ,vector<int> &widths
        ,int n
    )
{


    int increase=0;
    int decrease=0;

    vector<int>dp_increase = calcu_dp(heights,widths,n,[](int a,int b){return a>b;});
    vector<int>dp_decrease = calcu_dp(heights,widths,n,[](int a,int b){return a<b;});

    for(int i=0;i<n;i++){

        increase=max(increase,dp_increase[i]);
        decrease=max(decrease,dp_decrease[i]);

    }
   

    return{increase,decrease};

}

int main(){

//   freopen("entrada.txt", "r", stdin);
//   freopen("salida.txt", "w", stdout);

    int t;
    int n;
    int num;
    int cont = 1;

    vector<int>heights;
    vector<int>widths;

    pair<int,int>answer;

    cin>>t;

    while(t--){

        heights.clear();
        widths.clear();

        cin>>n;

        for(int i=0;i<n;i++){
            cin>>num;
            heights.push_back(num);
        }

        for(int i=0;i<n;i++){
            cin>>num;
            widths.push_back(num);
        }

        answer=dp_increase_decrease(heights,widths,n);

        if(answer.first>=answer.second){
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",cont++,answer.first,answer.second);
        }
        else{
            printf("Case %d. Decreasing (%d). Increasing (%d).\n",cont++,answer.second,answer.first);
        }

        

    }

    return 0;
}