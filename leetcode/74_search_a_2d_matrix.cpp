// 74.搜索二维矩阵
//
// 给你一个满足下述两条属性的 m x n 整数矩阵：
// * 每行中的整数从左到右按非严格递增顺序排列。
// * 每行的第一个整数大于前一行的最后一个整数。
// 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
// 你必须编写一个时间复杂度为 O(log(m * n)) 的解决方案。

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = m * n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int x = matrix[mid / n][mid % n];
        if (x < target) {
            low = mid + 1;
        } else if (x > target) {
            high = mid;
        } else {
            return true;
        }
    }
    return false;
}

