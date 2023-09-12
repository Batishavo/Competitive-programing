class Solution {
public:
    int hIndex(vector<int>& citations) {



        int n = citations.size();

        int answer = 0;
        
        sort(citations.begin(),citations.end());

        for(int i=n-1;i>=0;i--){
            if(answer+1<=citations[i]){
                answer++;
            }
            else{
                break;
            }
        }
        

        return answer;
    }
};