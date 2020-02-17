class Solution {
   public:
    int movingCount(int threshold, int rows, int cols) {
        // 记录是否访问过
        bool* visited = new bool[rows * cols];
        memset(visited, false, rows * cols);
        // 从(0,0)出发
        int count = move(threshold, rows, cols, 0, 0, visited);
        delete[] visited;
        return count;
    }

    int move(int threshold, int rows, int cols, int i, int j, bool* visited) {
        int index = i * cols + j;
        // 递归终止条件
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[index] ||
            getSum(i) + getSum(j) > threshold) {
            return 0;
        }
        // 设置访问标记
        visited[index] = true;
        // 遍历上下左右
        return move(threshold, rows, cols, i - 1, j, visited) +
               move(threshold, rows, cols, i + 1, j, visited) +
               move(threshold, rows, cols, i, j - 1, visited) +
               move(threshold, rows, cols, i, j + 1, visited) + 1;
    }
    // 计算位数之和
    int getSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};