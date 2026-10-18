class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        for(auto &edge: prerequisites){
            int couse=edge[0];
            int precouse=edge[1];
            graph[precouse].push_back(couse);
            ++indegree[couse];
        }

        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(indegree[i]==0)
                q.push(i);
        }
        int res=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            res++;
            for(auto index:graph[cur]){
                indegree[index]--;
                if(indegree[index]==0)
                    q.push(index);
            }
        }
        return res==numCourses?true:false;
    }
};