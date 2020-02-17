class Solution {
   public:
    bool duplicate(int numbers[], int length, int* duplication) {
        for (int i = 0; i < length; i++) {
            // 重复这个过程直到下标为 i 的位置上放的是数字 i
            while (numbers[i] != i) {
                int m = numbers[i];
                // 如果下标为 m 的位置上也是 m，则找到了重复的数字
                if (numbers[m] == m) {
                    *duplication = m;
                    return true;
                }
                // 否则，将数字 m 放到下标为 m 的位置上
                swap(numbers[i], numbers[m]);
            }
        }
        return false;
    }
};