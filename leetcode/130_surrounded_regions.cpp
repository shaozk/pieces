// 130.被环绕的区域
//
// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：
// * 连接：一个单元格与水平或垂直方向上相邻的单元格连接。
// * 区域：连接所有 'O' 的单元格来形成一个区域。
// * 围绕：如果一个区域中的所有 'O' 单元格都不在棋盘的边缘，则该区域被包围。这样的区域 完全 被 'X' 单元格包围。
// 通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。

void dfs(vector<vector<char>>& board, int r, int c) {
    if (board.empty()) return;
    int nr = board.size();
    int nc = board[0].size();
    if (r < 0 || r >= nr || c < 0 || c >= nc || board[r][c] != 'O') return;
    board[r][c] = 'A';
    dfs(board, r - 1, c);
    dfs(board, r + 1, c);
    dfs(board, r, c - 1);
    dfs(board, r, c + 1);
}

void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int nr = board.size();
    int nc = board[0].size();
    for (int i = 0; i < nr; ++i) {
        dfs(board, i, 0);
        dfs(board, i, nc - 1);
    }
    for (int j = 1; j < nc - 1; ++j) {
        dfs(board, 0, j);
        dfs(board, nr - 1, j);
    }
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {
            if (board[i][j] == 'A') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}
