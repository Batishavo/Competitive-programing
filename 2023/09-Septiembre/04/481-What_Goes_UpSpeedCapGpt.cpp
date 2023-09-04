#include<bits/stdc++.h>

using namespace std;

struct my_data
{
    vector<int> max_sub;
    int max_sum_size;

    my_data(){
        max_sum_size = 0;
    }

    my_data(vector<int>max_sub,int max_sum_size){
        this->max_sub = max_sub;
        this->max_sum_size = max_sum_size;
    }

};

my_data longest_sub_sequence(vector<my_data> &nums){

    int n = nums.size();

    vector<vector<int>> dp(n);
    dp[0] = nums[0].max_sub;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i].max_sub[0] > nums[j].max_sub.back()) {
                if(dp[i].size() < dp[j].size() + 1) {
                    dp[i] = dp[j];
                }
            }
        }
        dp[i].push_back(nums[i].max_sub[0]);
    }

    int pos = 0;
    for(int i = 1; i < n; i++) {
        if(dp[i].size() > dp[pos].size()) {
            pos = i;
        }
    }

    return {dp[pos], dp[pos].size()};
}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    vector<my_data> nums;

    int n;

    while (cin >> n) {
        nums.push_back({{n}, 1});
    }

    my_data answer = longest_sub_sequence(nums);

    cout << answer.max_sum_size << endl;
    cout << "-" << endl;
    for(int i = 0; i < answer.max_sub.size(); i++) {
        cout << answer.max_sub[i] << endl;
    }

    return 0;
}
