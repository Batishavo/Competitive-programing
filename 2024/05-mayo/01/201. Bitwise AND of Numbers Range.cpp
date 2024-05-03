class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int answer = 0;
        long long pot = 1;

        for(int i = 0; i<32;i++){
            if(pot>right){
                break;
            }
            if(
                (1<<i & left) &&
                (1<<i & right) &&
                (right-left)<=pot
            ){
                answer |= 1<< i;
            }
            pot*=2;
        }

        return answer;

    }
};