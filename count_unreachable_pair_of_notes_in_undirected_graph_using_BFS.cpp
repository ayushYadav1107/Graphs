class Solution {
public:
    typedef long long ll;
    void BFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,int &count){
        queue<int>q;
        visited[u] = true;
        q.push(u);
        count++;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &v: adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>adj;
        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll ans = 0;
        ll size = n;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int count = 0;
                BFS(adj,i,visited,count);
                size -= count;
                ans += size*(ll)count;
            }
        }
        return ans;
    }
};