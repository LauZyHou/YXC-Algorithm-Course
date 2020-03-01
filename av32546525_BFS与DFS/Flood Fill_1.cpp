/*
二维数组连通块染色
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty() || image[0].empty())
            return image;
        // 如果新旧颜色一样直接返回，防止死循环，因为后面检查的是颜色是不是旧颜色
        if(image[sr][sc]==newColor)
            return image;
        
        int ylen = image.size();
        int xlen = image[0].size();
        // 深搜技巧：把四个方向写到数组里
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        int old = image[sr][sc]; // 旧颜色
        image[sr][sc] = newColor; // 给开始点染色

        // 遍历这个点相邻的所有点
        for(int i=0;i<4;i++) {
            int y = sr + dy[i];
            int x = sc + dx[i];
            if(x>=0 && x<xlen && y>=0 && y<ylen && image[y][x]==old) {
                floodFill(image, y, x, newColor); // y行x列
            }
        }
        return image;
    }
};