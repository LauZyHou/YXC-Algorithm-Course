/*
一共32位，每一位都统计出现次数是不是模3余1
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int b=0;b<32;b++) {
            int cnt = 0;
            for(auto x:nums) {
                cnt += (x>>b)&1;
            }
            ans += (cnt%3)<<b;
        }
        return ans;
    }
};