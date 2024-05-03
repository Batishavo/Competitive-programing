class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long pos = 1;
        long left = x;
        long right = x;


        while(pos*10<=x){
            pos*=10;
        }
        //cout<<"pos :"<<pos<<endl;
        while(pos>0){
            //cout << left <<" "<<right<<endl;
            if(left%10 != right/pos){
                return false;
            }
            right = right -((right/pos)*pos);
            left/=10;
            pos/=10;
        }

        return true;
    }
};