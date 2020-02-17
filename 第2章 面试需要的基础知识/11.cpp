class Solution {
   public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) return 0;
        int low = 0, high = rotateArray.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (rotateArray[mid] > rotateArray[high]) {
                // mid 落在了前半段数组
                low = mid + 1;
            } else if (rotateArray[mid] < rotateArray[high]) {
                // mid 落在了后半段数组
                high = mid;
            } else {
                // 相同的时候只能遍历
                high = high - 1;
            }
        }
        return rotateArray[high];
    }
};