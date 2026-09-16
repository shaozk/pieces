// 994.腐烂的橘子
//
// 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
// * 值 0 代表空单元格；
// * 值 1 代表新鲜橘子；
// * 值 2 代表腐烂的橘子。
// 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
// 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty()) return -1;
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> que;
    int fresh = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) fresh += 1;
            else if (grid[i][j] == 2) que.push({i, j});
        }
    }
    if (fresh == 0) return 0;
    int ret = 0;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!que.empty() && fresh > 0) {
        ++ret;
        int sz = que.size();
        for (int k = 0; k < sz; ++k) {
            auto [x, y] = que.front(); que.pop();
            for (auto& [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    --fresh;
                    que.push({nx, ny});
                }
            }
            
        }
    }
    return fresh == 0 ? ret : -1;
}
