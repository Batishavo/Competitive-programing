class Solution {
public:

    bool singleMutation(string current,string mutation){
        int cont = 0;
        for(int i=0;i<8;i++){
            if(current[i]!=mutation[i]){
                cont++;
            }
        }
        return cont<=1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        map<string,int>memo;
        
        bool flag = false;

        int n = bank.size();

        queue<string>bfs;

        for(int i = 0;i<n;i++){
            memo[bank[i]]=INT_MAX;
        }

        memo[startGene] = 0;

        bfs.push(startGene);

        while(!bfs.empty()){
            string currentGene = bfs.front();
            int mutation = memo[currentGene];
            bfs.pop();
            if(currentGene == endGene){
                flag = true;
            }
            for(int i=0;i<n;i++){
                if(singleMutation(currentGene,bank[i]) &&  memo[bank[i]]> mutation+1){
                    memo[bank[i]] = mutation+1;
                    bfs.push(bank[i]);
                }
            }
        }

        return flag?memo[endGene]:-1;
    }
};