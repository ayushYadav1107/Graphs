class Solution {
public:
    typedef long long ll;
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent){
            return;
        }
        
        if(x_parent > y_parent){
            parent[y_parent] = x_parent;
        }else if(x_parent < y_parent){
            parent[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        // making components
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            Union(u,v);
        }

        // mapping parent(component) --> size of component
        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++){
            int parent = find(i);
            mpp[parent]++;
        }
        // traversing the map to get the component nodes count
        int size = n;
        ll ans = 0;
        
        for(auto &it : mpp){
            int count = it.second;
            size -= count;
            ans += ll(size)*ll(count); 
        }
        return ans;
    }
};