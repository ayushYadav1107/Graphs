class Solution {
public:
    vector<int>rank;
    vector<int>parent;

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent){
            return;
        }
        
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalEdges = connections.size();
        if(totalEdges < n-1) return -1; // it is not possible if less than n-1

        rank.resize(n,0);
        parent.resize(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        int components = n; //initially all are separate components
        for(auto &edge : connections){
            int x_parent = find(edge[0]);
            int y_parent = find(edge[1]);

            if(x_parent != y_parent){ // take union and reduce components
                Union(x_parent,y_parent);
                components--;
            }
        }
        return components-1;
    }
};