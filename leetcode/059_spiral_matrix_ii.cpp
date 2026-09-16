// 59.螺旋矩阵 II
// 
// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> mat(n, vector<int>(n));
    int num = 1;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    while (left <= right && top <= bottom) {
        for (int j = left; j <= right; ++j) {
            mat[top][j] = num++;
        }
        for (int i = top + 1; i <= bottom; ++i) {
            mat[i][right] = num++;
        }
        if (left < right && top < bottom) {
            for (int j = right - 1; j > left; --j) {
                mat[bottom][j] = num++;
            }
            for (int i = bottom; i > top; --i) {
                mat[i][left] = num++;
            }
        }
        ++left;
        --right;
        ++top;
        --bottom;
    }
    return mat;
    
}
