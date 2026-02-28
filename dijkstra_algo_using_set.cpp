class Solution {
  public:
  #define P pair<int,int>
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,vector<P>>adj;
        for(int i = 0; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }
        set<P>st; // using set to get rid of some extra checks
        vector<int>result(V,INT_MAX);
        result[src] = 0;
        st.insert({0,src});
        
        while(!st.empty()){
            auto &it = *st.begin();
            int dist = it.first;
            int u = it.second;
            st.erase(it);
            
            for(auto &node : adj[u]){
                int w = node.first;
                int v = node.second;
                
                if(dist + w < result[v]){
                    
                    if(result[v] != INT_MAX){ // if we already have a better answer erase the other one
                        st.erase({result[v],v});
                    }
                    result[v] = dist+w;
                    st.insert({dist+w,v});
                }
            }
        }
        return result;
    }
};