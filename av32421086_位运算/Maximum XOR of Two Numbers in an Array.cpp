/*
O(n)时间求给定数组中最大的异或和

1. 每一位尽可能不一样
2. 因为2^k 严格大于 2^{k-1}+2^{k-2}...
所以高位提供的价值严格大于低位，所以可以贪心地从高位开始，总是选当前这位异或尽量是1的
所以对于选的x^y如果x最高位是0，那么只要有最高位是1的y就一定比最高位不是1的y要好

用Trie树，把数字每一位当成单词用就行
https://www.acwing.com/solution/LeetCode/content/549/
在Trie树中每次贪心地尽可能向相反的方向(1/0相反)走
因此O(n)的时间枚举每个x，然后O(31)的时间在Trie树中找最合适的y
*/

class Solution {
public:
    struct Node
    {
        int son[2]; // 这里用int是存在下面nodes数组中的下标
    };
    vector<Node> nodes;// Trie树的结点

    int findMaximumXOR(vector<int>& nums) {
        nodes.push_back(Node{0,0}); // 根节点

        // O(n)建立Trie树，即把所有结点插入进去
        for(auto x:nums) {
            int p = 0; // 从根节点开始遍历
            for(int i=30;i>=0;i--) { // 枚举x的所有位，从高位到低位
                int t = x>>i & 1; // 把x当前第i位取出来
                // 先判断子结点是不是存在，不存在就要创建
                if(!nodes[p].son[t]) {
                    nodes.push_back(Node{0,0});
                    nodes[p].son[t] = nodes.size()-1; // 即刚刚创建插入进去的下标
                }
                // t如果是0就往右走，1就往左走
                p = nodes[p].son[t];
            }
        }

        // O(n)枚举所有的x找最合适的y
        int ans = 0;
        for(auto x:nums) {
            int p = 0; // 根节点开始i
            int xXORy = 0; // 最合适的x^y
            for(int i=30;i>=0;i--) { // 从最高位向最低位贪心
                int t = x>>i & 1; // 取出当前位是1还是0
                // 尽可能向相反方向走，也就是先看相反方向存在不存在路径
                if(nodes[p].son[!t]) {
                    p = nodes[p].son[!t]; // 走过去
                    xXORy |= 1<<i; // 当前位设置成1
                }
                // 反之没有那个方向路径，只能和自己一样的方向走
                // 这里不用判断存不存在，因为x自己都存在，所以这个方向的结点一定存在
                else
                    p = nodes[p].son[t];
            }
            ans = max(ans, xXORy);
        }
        return ans;
    }
};