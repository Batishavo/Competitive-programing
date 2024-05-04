class Solution {
public:
    string longestPalindrome(string s) {
        
        if(isPalindorme(s)){
            return s;
        }

        string answer = "";

        int n = s.size();

        int mayor = 0;
        int pos = 0;

        int mayorEven = 0;
        int posEven = 0;

        for(int i = 0;i<s.size();i++){

            int num = maximo(s,i,n);
            int numEven = maximoEven(s,i,n);

            if(num>mayor){
                pos = i;
                mayor = num;
            }
            if(numEven>mayorEven){
                posEven = i;
                mayorEven = numEven;
            }

        }

        if(mayor*2+1>mayorEven*2){
            //cout<<"odd"<<endl;
            for(int i=pos-mayor;i<=pos+mayor;i++){
                answer += s[i];
            }
        }
        else{
            //cout<<posEven<<" "<<mayorEven<<endl;
            //cout<<"even"<<endl;
            for(int i=posEven-mayorEven+1;i<=posEven+mayorEven;i++){
                answer += s[i];
            }
        }

       

        return answer;
    }

private:

    bool isPalindorme(string &s){
        int left = 0;
        int right = s.size()-1;

        while(left<s.size() && right>=0){

            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;

        }

        return true;

    }

    int maximo(string &s,int pos,int n){
        int cont = 0;
        while(
            pos+cont+1<n &&
            pos-cont-1>=0 &&
            s[pos+cont+1] == s[pos-cont-1]
        ){
            cont++;
        }
        return cont;
    }

    int maximoEven(string &s,int pos,int n){
        int cont = 0;
        int left = pos;
        int right = pos+1;
        while(
            left>=0 &&
            right<n &&
            s[left] == s[right]
        ){
            cont++;
            left--;
            right++;
        }

        return cont;
    }
};