class Solution {
public:

    map<int,vector<char>> letters;

    Solution(){
        char letter = 'a';
        for(int i=2;i<=9;i++){
            int num = i==7||i==9?4:3;
            for(int j=0;j<num;j++){
                letters[i].push_back(letter);
                letter++;
            }
        }
        letters['z'].push_back(letter);
    }

    vector<string> dp(
        string &digits,
        int pos,
        string cad
    ){
        vector<string> result;
        if(pos == digits.size()){
            result.push_back(cad);
            return result;
        }
        int num = digits[pos]-'0';
        for(char letter:letters[num]){
            vector<string> combinations = dp(digits,pos+1,cad+letter);
            result.insert(result.end(), combinations.begin(), combinations.end());
        }
        return result;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return vector<string>();
        }
        return dp(digits,0,"");
    }
// };