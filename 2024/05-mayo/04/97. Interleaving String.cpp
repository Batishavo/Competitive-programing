class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        if(s1=="" && s2=="" && s3==""){
            return true;
        }

        if(s1.size()+s2.size()<s3.size() || s1.size()+s2.size()>s3.size()){
            return false;
        }

        bool flag = false;
        dp(s1,s2,s3,0,0,0,flag);
        return flag;
    }

private:
    void dp(
        string &s1, 
        string &s2, 
        string &s3,
        int p1,
        int p2,
        int p3,
        bool &flag
    ){

        if(flag){
            return;
        }

        if(p1+p2 == s3.size()){

            if(
                (p1 == 0 && s1.size()>0) || (p2 == 0 && s2.size()>0) ||
                (p2<s2.size() || p1<s1.size())
            ){
                return;
            }

            flag = true;

            return;
        }


        if(s1[p1] == s3[p3]){
            dp(s1,s2,s3,p1+1,p2,p3+1,flag);
        }

        if(!flag && s2[p2] == s3[p3]){
           dp(s1,s2,s3,p1,p2+1,p3+1,flag);
        }


    }

};