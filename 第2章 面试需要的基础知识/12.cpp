class Solution {
   public:
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        // 标志位，初始化为false
        bool* flag = new bool[rows * cols];
        memset(flag, false, rows * cols);
        // 循环遍历二维数组，找到起点等于str第一个元素的值，再递归判断四周是否有符合条件的----回溯法
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (has(matrix, rows, cols, i, j, str, 0, flag)) {
                    return true;
                }
            }
        }
        delete[] flag;
        return false;
    }

    bool has(char* M, int rows, int cols, int i, int j, char* S, int k,
             bool* flag) {
        int index = i * cols + j;
        // 递归终止条件
        if (i < 0 || j < 0 || i >= rows || j >= cols || flag[index] == true ||
            S[k] != M[index]) {
            return false;
        }
        // 若k已经到达str末尾了，说明之前的都已经匹配成功了，直接返回true即可
        if (S[k + 1] == '\0') return true;
        // 要走的第一个位置置为true，表示已经走过了
        flag[index] = true;
        if (has(M, rows, cols, i - 1, j, S, k + 1, flag) ||
            has(M, rows, cols, i + 1, j, S, k + 1, flag) ||
            has(M, rows, cols, i, j - 1, S, k + 1, flag) ||
            has(M, rows, cols, i, j + 1, S, k + 1, flag)) {
            return true;
        }
        // 走到这，说明这一条路不通，还原，再试其他的路径
        flag[index] = false;
        return false;
    }
};