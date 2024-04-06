class Solution {
public:

    bool topologicalSort(
        map<int,int>&tmpVisited,
        map<int,int>&visited,
        map<int,vector<int>>&grap,
        vector<int> &answer,
        int node
    ){
       
        if(tmpVisited[node] == 1){
            return false;
        }
        if(visited[node]==1){
            return true;
        }
        tmpVisited[node]=1;
        for(auto x:grap[node]){
            if(!topologicalSort(
                tmpVisited,
                visited,
                grap,
                answer,
                x

            )){
                return false;
            } 
        }
        tmpVisited[node]=0;
        visited[node]=1;
         answer.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> answer;
        
        map<int,int>tmpVisited;
        map<int,int>visited;
        map<int,vector<int>>grap;

        int n = prerequisites.size();

        for(int i=0;i<n;i++){
            grap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i] &&
                !topologicalSort(
                    tmpVisited,
                    visited,
                    grap,
                    answer,
                    i
                )
            ){
                
                return vector<int>();
            }
        }
        
        return answer;
    }
};