class Solution {
   public:
    int NumberOf1(int n) {
        int ans = 0;
        while (n) {
            // 有多少个1，就可以进行多少次这样的操作
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }
};