/*
利用XOR是不进位加法，而且(a&b)<<1就是它的进位
递归出口就是没有进位的时候
*/

class Solution {
public:
    int getSum(int a, int b) {
        if(!b)
            return a;
        int s = a^b;
        int carry = uint(a&b)<<1; // 这里强制转换为无符号,不然得到的是负数的话左移有问题
        return getSum(s, carry);
    }
};