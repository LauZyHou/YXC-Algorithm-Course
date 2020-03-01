/*
图论问题，从0点到n点一共n+1个点
如果某个数x加上一个平方数能到另一个数y
就在x和y之间连一条有向边，权重是1
所求是从0到n的最短路
用BFS实现
*/

class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<int> dist(n+1, INT_MAX); // 记录所有点到0点的距离
        q.push(0); // 从0开始搜索
        dist[0] = 0; // 0到0的距离是0
        while(q.size()) {
            // BFS每次取队头
            int t = q.front();
            q.pop();
            // 如果已经搜索到n了，那么dist中就保存过dist[n]了直接返回
            if(t==n)
                return dist[n];
            // 否则对于该结点的所有子结点(即从该结点+一个平方数i^2)
            for(int i=1;i*i+t<=n;i++) {
                int j = t+i*i; // 加完平方数的子结点
                // 如果到j的距离可以被这次通过t的搜索更新
                if(dist[j] > dist[t]+1) {
                    dist[j] = dist[t]+1;
                    q.push(j);
                }
            }
        }
        // 至此说明搜不到
        // 实际上该题一定有解，不会执行这里，因为大不了就全用1=1^2加起来再+t来表示n
        return 0;
    }
};