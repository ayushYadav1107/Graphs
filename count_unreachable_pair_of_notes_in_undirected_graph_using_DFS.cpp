class Solution {
public:
    typedef long long ll;
    void DFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,int &count){
        visited[u] = true;
        count++;
        for(auto &v : adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited,count);
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
                DFS(adj,i,visited,count); // no of nodes in component
                size -= count; //removing it to make sure it doesn't repeat
                ans += size*(ll)count; // no of unreachable nodes
            }
        }
        return ans;
    }
};