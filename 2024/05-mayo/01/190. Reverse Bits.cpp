class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t answer = 0;
        int pos = 31;
        for(int i = 0;i<32;i++){
            if(1<<i & n){
                answer = answer | 1 << pos; 
            }
            pos--;
        }

        return answer;
    }
};