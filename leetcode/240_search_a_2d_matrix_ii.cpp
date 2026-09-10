// 240.搜索二维码矩阵II
//
// 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
// * 每行的元素从左到右升序排列。
// * 每列的元素从上到下升序排列。

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix.at(0).size();
    int x = 0, y = n - 1;
    while (x < m && y >= 0) {
        if (target == matrix[x][y]) {
            return true;
        } else if (target < matrix[x][y]) {
            --y;
        } else {
            ++x;
        }
    }
    return false;
}
