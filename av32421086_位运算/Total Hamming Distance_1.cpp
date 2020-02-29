/*
两个数之间的Hamming距离其二进制表示中不同数位的个数。
现在，你的任务是计算给定的数组中，所有数对的Hamming距离。

如果只有两个数，异或一下再看有几个1就行了
现在有这么多数，不妨对每一位看看有几个数是1几个数是0
那最后这一位导致的汉明距离就是取1的数的数量*取0的数的数量
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        for(int i=0;i<31;i++) {
            int ones = 0;
            for(auto x:nums) {
                if(x>>i & 1)
                    ones++;
            }
            ans += ones*(len-ones);
        }
        return ans;
    }
};