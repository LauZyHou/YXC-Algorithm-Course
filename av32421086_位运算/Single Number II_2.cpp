/*
状态机的方法
(ones,twos)在一起能表示32位每一位数字出现(1次?,2次?)

对每一位:
初始            (0,0)
该位送入一个1    (1,0)
该位送入两个1    (0,1)
该位送入三个1    (0,0) 即重置了

因此所有模3为1的地方在ones里都是1,不为1的地方在ones里就是0
最终返回ones
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(auto x:nums) {
            ones = (ones^x) & ~twos;//这里~是按位取反
            twos = (twos^x) & ~ones;
        }
        return ones;
    }
};