class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());

        bool flag = false;

        for(int i = 0; i<digits.size();i++){
            if(digits[i]+1<=9){
                digits[i]++;
                flag = true;
                break;
            }
            else{
                digits[i] = 0;
        
            }
        }

        if(!flag){
            digits.push_back(1);
        }

        reverse(digits.begin(),digits.end());
        return digits;        
    }
};