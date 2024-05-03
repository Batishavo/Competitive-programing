class Solution {
private:
    struct MinComparator {
        bool operator()(int a, int b) const {
            return a < b; // Invertimos el orden para hacer un min-heap
        }
    };

public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(),MinComparator());
       
        /*while(nums.size()>0){
            cout<<nums.front()<<endl;
            pop_heap(nums.begin(), nums.end(), MinComparator());
            nums.pop_back();
        }*/
       
        while(k!=1){
            cout<<nums.front()<<endl;
            pop_heap(nums.begin(), nums.end(), MinComparator());
            nums.pop_back();
            k--;
        }
        return nums.front();
        //return 0;
    }
};