class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> degree(numCourses,0);
        queue<int> zeroDegree;
        vector<vector<int>> graph(numCourses,vector<int>());
        for(auto p:prerequisites)
        {
            graph[p.second].push_back(p.first);
            degree[p.first]++;
        }
        for(int i=0;i<numCourses;++i)
        {
            if(0==degree[i])
                zeroDegree.push(i);
        }
        while(!zeroDegree.empty())
        {
            int t=zeroDegree.front();
            zeroDegree.pop();
            for(auto i:graph[t])
            {
                if(0==degree[i])
                    continue;
                if(--degree[i]==0)
                    zeroDegree.push(i);
            }
        }
        bool ret=true;
        for(int i=0;i<numCourses;++i)
        {
            if(0!=degree[i])
            {
                ret=false;
                break;
            }
        }
        return ret;
    }
};