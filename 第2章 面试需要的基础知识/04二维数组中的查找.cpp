class Solution {
   public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        /*  矩阵形式
            小 → 大
            ↓    ↓
            大 → 大大
         从左下角开始查找
        */
        int i = row - 1, j = 0;
        while (i >= 0 && j < col) {
            // 小于目标值则指针右移
            if (array[i][j] < target) j++;
            // 大于目标值则指针上移
            else if (array[i][j] > target)
                i--;
            else
                return true;
        }
        return false;
    }
};