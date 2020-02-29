/*
每次将n最低位的一个1去掉，然后看是否已经等于m或比m小，如果是则返回当前的n
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(n>m) {
            n &= n-1;
        }
        return n;
    }
};