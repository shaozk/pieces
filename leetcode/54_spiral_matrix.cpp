// 54.螺旋矩阵
// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result = {};
        if (matrix.size() == 0 || matrix.at(0).size() == 0) {
            return result;
        }
        int m = matrix.size(), n = matrix.at(0).size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; ++j) {
                result.push_back(matrix[top][j]);
            }
            for (int i = top + 1; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            if (left < right && top < bottom) {
                for (int j = right - 1; j > left; --j) {
                    result.push_back(matrix[bottom][j]);
                }
                for (int i = bottom; i > top; --i) {
                    result.push_back(matrix[i][left]);
                }
             }
            ++top;
            --bottom;
            ++left;
            --right;
        }
        return result;
    }
};
