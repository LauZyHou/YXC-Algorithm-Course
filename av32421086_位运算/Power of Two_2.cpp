/*
n & -n 等于n的二进制表示里最靠右的那个1
所以如果n & -n == n 也就是二进制表示里只有一个1，那就是2的整数次幂
如果n不是2的整数次幂，那么n&-n < n
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & -n)==n;
    }
};