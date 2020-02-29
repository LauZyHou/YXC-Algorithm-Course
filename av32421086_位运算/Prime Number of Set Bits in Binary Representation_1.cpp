/*
因为L到R是1~10^6，10^6小于2^20，所以最多不超过20个二进制位
那么涉及的质数就是2到19
*/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> us({2,3,5,7,11,13,17,19});
        int ans = 0;
        for(int i=L;i<=R;i++) {
            int cnt = 0;
            for(int k=i;k;k>>=1)
                cnt+= k&1;
            if(us.count(cnt))
                ans++;
        }
        return ans;
    }
};