class Solution {
  public:
    typedef pair<int,int>P;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<P>>adj; // node -> (weight,neighbor)
        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }
        
        vector<int>result(n+1,INT_MAX);
        priority_queue<P,vector<P>,greater<P>>pq;
        
        result[1] = 0; // distance from src -> src
        pq.push({0,1}); // initializing pq with src --> src (0)
        vector<int>parent(n+1); // from which node we got the better answer
        vector<int>path;
        for(int i = 0; i <=n;i++){
            parent[i] = i;
        }
        
        while(!pq.empty()){
            auto [dist,node] = pq.top();
            pq.pop();
            if(dist > result[node]) continue; // skipping stale entries
            
            for(auto &it : adj[node]){
                int d = it.first;
                int v = it.second;
                
                if(dist+d < result[v]){ // if distance is less than we got better path
                    result[v] = dist+d;
                    parent[v] = node;
                    pq.push({dist+d,v}); // push the better path in priority queue
                }
            }
        }
        if(result[n]==INT_MAX) return {-1};
        
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(result[n]);
        reverse(path.begin(),path.end());
        return path;
    }
};