class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int loc = 0;
        while(num) {
            ans += !(num&1) << loc;// 加上[那一位取反,再放到相应位置]的值
            num >>= 1;
            loc++;
        }
        return ans;
    }
};