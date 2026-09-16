// 695.岛屿的最大面积
//
// 给你一个大小为 m x n 的二进制矩阵 grid 。
// 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
// 岛屿的面积是岛上值为 1 的单元格的数目。
// 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。


int dfs(vector<vector<int>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();
    if (r < 0 || r >= nr || c < 0 || c >= nc || grid[r][c] != 1) return 0;
    int area = 0;
    grid[r][c] = 0;
    area += 1;
    area += dfs(grid, r - 1, c);
    area += dfs(grid, r + 1, c);
    area += dfs(grid, r, c - 1);
    area += dfs(grid, r, c + 1);
    return area;
  
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int nr = grid.size();
    int nc = grid[0].size();
    int max_area = 0;
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {
            max_area = max(max_area, dfs(grid, i, j));
        }
    }
    return max_area;
  
}

