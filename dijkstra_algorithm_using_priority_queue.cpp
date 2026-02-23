class Solution {
  public:
    typedef pair<int,int> P;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,vector<P>>adj; // node -> (weight,neighbor)
        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }
        
        vector<int>result(V,INT_MAX);
        priority_queue<P,vector<P>,greater<P>>pq;
        
        result[src] = 0; // distance from src -> src
        pq.push({0,src}); // initializing pq with src --> src (0)
        
        while(!pq.empty()){
            auto [dist,node] = pq.top();
            pq.pop();
            if(dist > result[node]) continue; // skipping stale entries
            
            for(auto &it : adj[node]){
                int d = it.first;
                int v = it.second;
                
                if(dist+d < result[v]){ // if distance is less than we got better path
                    result[v] = dist+d;
                    pq.push({dist+d,v}); // push the better path in priority queue
                }
            }
        }
        return result;
    }
};