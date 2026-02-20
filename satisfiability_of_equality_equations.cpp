class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent){ // no need for union
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
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);

        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }

        for(auto &s : equations){
            if(s[1]=='='){ // union of equal characters
                Union(s[0]-'a',s[3]-'a');
            }
        }
        // a!=b case
        for(auto &s : equations){
            if(s[1]=='!'){
                int parent1 = s[0]-'a';
                int parent2 = s[3]-'a';

                if(find(parent1)==find(parent2)){
                    return false;
                }
            }
        }
        return true;
    }
};