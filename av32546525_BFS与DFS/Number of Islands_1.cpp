/*
统计=1的连通块的个数
*/

class Solution {
private:
    int rowlen;
    int collen;
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        rowlen = grid.size();
        collen = grid[0].size();
        int ans = 0;
        for(int i=0;i<rowlen;i++) {
            for(int j=0;j<collen;j++) {
                if(grid[i][j]=='1') {
                    ans++;
                    dfs(grid, i, j); // 把这个连通快都变成0
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& g, int x, int y) {
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        g[x][y] = '0';
        for(int i=0;i<4;i++) {
            int a = x+dx[i];
            int b = y+dy[i];
            if(a>=0 && a<rowlen && b>=0 && b<collen && g[a][b]=='1') {
                dfs(g, a, b);
            }
        }
    }
};