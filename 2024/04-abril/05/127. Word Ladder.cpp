class Solution {
public:

    bool singleChange(string current,string mutation){
        int cont = 0;
        for(int i=0;i<current.size();i++){
            if(current[i]!=mutation[i]){
                cont++;
            }
        }
        return cont<=1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int>memo;
        
        bool flag = false;

        int n = wordList.size();

        queue<string>bfs;

        for(int i = 0;i<n;i++){
            memo[wordList[i]]=INT_MAX;
        }

        memo[beginWord] = 1;

        bfs.push(beginWord);

        while(!bfs.empty()){
            string currentWord = bfs.front();
            int transformSequence = memo[currentWord];
            bfs.pop();
            if(currentWord == endWord ){
                flag = true;
            }

            for(int i=0;i<n;i++){
                if(singleChange(currentWord,wordList[i]) && 
                    memo[wordList[i]]>transformSequence+1
                ){
                    memo[wordList[i]] = transformSequence+1;
                    bfs.push(wordList[i]);
                }
            }
        }

        return flag?memo[endWord]:0;
    }
};