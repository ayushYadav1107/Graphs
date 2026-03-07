class Solution {
public:
    #define P pair<int,pair<int,int>>
    vector<vector<int>>directions{{0,-1},{-1,0},{1,0},{0,1},{1,1},{-1,-1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto isSafe = [&](int x, int y){
            if((x >= 0 && x <m) && (y >=0 && y < n)){
                return true;
            }
            return false;
        };

        if(grid[0][0]==1){
            return -1;
        }

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        result[0][0] = 1;
        pq.push({1,{0,0}});
        grid[0][0] = 1;

        while(!pq.empty()){
            P element = pq.top();
            pq.pop();
            int d = element.first;
            int i = element.second.first;
            int j = element.second.second;

            if(d > result[i][j]) continue;
            for(auto &dir : directions){
                int x = i + dir[0];
                int y = j + dir[1];

                if(isSafe(x,y) && grid[x][y]==0){
                    if( d + 1 < result[x][y]){
                        result[x][y] = d + 1;
                        pq.push({d+1,{x,y}});
                    }
                }
            }
        }
        if(result[m-1][n-1]==INT_MAX){
            return -1;
        }
        return result[m-1][n-1];
    }
};


// using BFS
class Solution {
public:
    vector<vector<int>>directions{{0,-1},{-1,0},{1,0},{0,1},{1,1},{-1,-1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0]==1) return -1;

        auto isSafe = [&](int x, int y){
            if((x >= 0 && x <m) && (y >=0 && y < n)){
                return true;
            }
            return false;
        };

        int level = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        while(!q.empty()){

            int N = q.size();

            while(N--){
                auto [i,j] = q.front();
                q.pop();

                if(i==m-1 && j==n-1) return level+1;

                for(auto &dir : directions){
                    int x = i + dir[0];
                    int y = j + dir[1];

                    if(isSafe(x,y) && grid[x][y]==0){
                        q.push({x,y});
                        grid[x][y]=1; // marking visited
                    }
                }
            }
            level++;
        }
        return -1;
    }
};