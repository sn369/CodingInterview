class Solution {
   public:
    int cutRope(int number) {
        // 当 n == 2 时，1,1 乘积最大
        if (number == 2) return 1;
        // 当 n == 3 时，1,2 乘积最大
        if (number == 3) return 2;
        vector<int> dp(number + 1);
        // 当 n > 3时，跟n<=3不同，4可以分很多段，比如分成1、3，
        // 这里的3可以不需要再分了，因为3分段最大才2，不分就是3，记录最大的。
        for (int i = 0; i <= 3; i++) {
            dp[i] = i;
        }
        // 动态规划
        for (int i = 4; i <= number; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], dp[i - j] * dp[j]);
            }
        }
        return dp[number];
    }
};

class Solution {
   public:
    int cutRope(int number) {
        // n = 1,2,3 时单独考虑
        if (number <= 3) return number - 1;
        // 尽可能多地剪去长度为 3 的绳子段
        int num_3 = number / 3;
        // 当绳子剩下长度为 4 时，不剪去长度为3的绳子段
        // 此时更好的是分成2，2，因为2*2>1*3
        if (number % 3 == 1) {
            num_3--;
        }
        // 最终剩下的只可能是长度为0或2的绳子
        int num_2 = (number - num_3 * 3) / 2;
        return pow(3, num_3) * pow(2, num_2);
    }
};