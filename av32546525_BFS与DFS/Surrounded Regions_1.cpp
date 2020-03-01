/*
把图中所有被四个方向'X'包围的'O'都换成'X'
边不能算包围

可以考虑把最后能活下来的'O'标记一下(变成'Y')，其他的都变成'X'即可
所以只要找能活的'O'，只要从边界开始搜索
*/

class Solution {
private:
    int rowlen;
    int collen;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return ;
        rowlen = board.size();
        collen = board[0].size();
        // 遍历左右两栏
        for(int i=0;i<rowlen;i++) {
            if(board[i][0]=='O')
                dfs(board, i, 0);
            if(board[i][collen-1]=='O')
                dfs(board, i, collen-1);
        }
        // 遍历上下两栏
        for(int j=0;j<collen;j++) {
            if(board[0][j]=='O')
                dfs(board, 0, j);
            if(board[rowlen-1][j]=='O')
                dfs(board, rowlen-1, j);
        }

        // 将没变成'Y'的'O'变成'X'
        for(int i=0;i<rowlen;i++) {
            for(int j=0;j<collen;j++) {
                if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }

        // 将'Y'变成'O'
        for(int i=0;i<rowlen;i++) {
            for(int j=0;j<collen;j++) {
                if(board[i][j]=='Y')
                    board[i][j]='O'; 
            }
        }
    }

    // 将联通的'O'变成'Y'
    void dfs(vector<vector<char>>& g, int x, int y) {
        g[x][y] = 'Y';
        for(int i=0;i<4;i++) {
            int a = x+dx[i];
            int b = y+dy[i];
            if(a>=0 && a<rowlen && b>=0 && b<collen && g[a][b]=='O')
                dfs(g, a, b);
        }
    }
};