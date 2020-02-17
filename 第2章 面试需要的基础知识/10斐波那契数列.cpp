class Solution {
   public:
    int Fibonacci(int n) {
        /*
        x  y
        0, 1,  1, 2, 3, 5, ...
               y = x + y
           x = y - x (即为原来的 y )
        */
        int x = 0, y = 1;
        while (n--) {
            y = x + y;
            x = y - x;
        }
        // n 次操作，得到第 n 位
        return x;
    }
};