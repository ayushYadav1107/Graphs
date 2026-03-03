class Solution {
public:
    typedef pair<int,int>P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int,vector<P>>adj; // node -> (weight,neighbor)
        for(int i = 0; i < times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            
            adj[u].push_back({w,v});
        }
        
        vector<int>result(n+1,INT_MAX);
        priority_queue<P,vector<P>,greater<P>>pq;

        result[k] = 0;
        pq.push({0,k});

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
        for(int i = 1; i < result.size();i++){
            if(result[i]==INT_MAX){
                return -1;
            }
        }
        int min_time = *max_element(result.begin()+1,result.end());
        return min_time;
    }
};