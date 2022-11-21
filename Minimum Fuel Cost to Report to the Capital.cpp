class Solution {
public:
    long long ans = 0;
    vector<vector<int>> graph;
    vector<bool> vis;         
    long long dfs(int node,int seats,long long count)
    {
        vis[node]=true;
        long long temp=1;
        for(auto it: graph[node])
        {
            if(!vis[it])
            {
                temp+=dfs(it,seats,0);
            }
        }
        ans+= (temp+seats-1)/seats;
        return temp;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        graph.resize(n+1);
        vis.resize(n+1,false);
        for(auto x:roads)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vis[0]=true;
        for(auto x : graph[0])
        {
            long long count =0;
            dfs(x,seats,count);
        }
        return ans;
    }
};
