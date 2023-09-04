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

    vector<int> arr;

    for(int i=0;i<n;i++){
        arr.push_back(nums[i].max_sub[0]);
    }

    

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                if(nums[i].max_sum_size<=nums[j].max_sum_size+1){
                    vector<int>tmp =nums[j].max_sub;
                    tmp.push_back(arr[i]);
                    nums[i]={tmp,nums[j].max_sum_size+1};
                }
            }
        }
    }    

    int pos = 0;

    for(int i=1;i<n;i++){
        if(nums[i].max_sum_size>=nums[pos].max_sum_size){
            pos = i;
        }
    }

    return nums[pos];
}

int main(){

    // freopen("entrada.txt", "r", stdin);
    // freopen("salida.txt", "w", stdout);

    vector<my_data>nums;

    int n;

    while (cin>>n)
    {
        nums.push_back({{n},1});
    }
    

    my_data answer = longest_sub_sequence(nums);

    cout<<answer.max_sum_size<<endl;
    cout<<"-"<<endl;
    for(int i=0;i<answer.max_sub.size();i++){
        cout<<answer.max_sub[i]<<endl;
    }

    return 0;
}