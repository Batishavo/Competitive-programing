class Solution {
public:

   

    bool topologicalSort(
        map<int,vector<int>> &requerimients,
        map<int,int> &visited,
        map<int,int> &tempVisited,
        int num
    ){

        cout<<num<<endl;

        if(tempVisited[num]==1){
            return false;
        }    
        if(visited[num]==1){
            return true;
        }
        tempVisited[num] = 1;
         for(auto x:requerimients[num]){
            if(!topologicalSort(requerimients, visited, tempVisited, x)) {
                return false;
            }
        }
        tempVisited[num]=0;
        visited[num]=1;
        return true;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n =prerequisites.size();
        map<int,vector<int>> requerimients;
        map<int,int>tempVisited;
        map<int,int> visited;
        
        for(int i=0;i<n;i++){
            requerimients[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }


        for(int i=0;i<n;i++){
            
            if(visited[ prerequisites[i][0]]==0){
                if(!topologicalSort(
                    requerimients,
                    visited,
                    tempVisited,
                    prerequisites[i][0]
                )){
                    return false;
                }
            }
           
        }
        
        return true;

    }
};