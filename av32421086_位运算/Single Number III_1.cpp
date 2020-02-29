class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for(auto x:nums)
            s ^= x;
        // 这两个数异或结果是1的位置就是这两个数不同的位置
        // 这样的位置至少有一个,随便找一个这个位置k
        // 然后把数组按照这一位是1还是0划分成两部分
        // 这两部分就分别是Single Number I的问题了
        int k = 0;
        while((s>>k & 1)==0)
            k++;

        int ans1=0,ans2=0;
        for(auto x:nums) {
            if(x>>k & 1)
                ans1 ^= x;
            else
                ans2 ^= x;
        }
        return vector<int>({ans1,ans2});
    }
};