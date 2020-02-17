class Solution {
   public:
    void replaceSpace(char *str, int length) {
        // j 指向字符串末尾
        int j = length - 1;
        // 从前向后遍历，每遇到 1 个空格，则 j 向后移动 2 位
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                j += 2;
            }
        }
        // 从后向前遍历
        for (int i = length - 1; i >= 0; i--) {
            // 若为空格，则填充 %20
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            } else {
                // 否则复制原字符
                str[j--] = str[i];
            }
        }
    }
};