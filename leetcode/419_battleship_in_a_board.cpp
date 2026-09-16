// 419.棋盘上的战舰
//
// 给你一个大小为 m x n 的矩阵 board 表示棋盘，其中，每个单元格可以是一艘战舰 'X' 或者是一个空位 '.' ，返回在棋盘 board 上放置的 舰队 的数量。
// 舰队 只能水平或者垂直放置在 board 上。换句话说，舰队只能按 1 x k（1 行，k 列）或 k x 1（k 行，1 列）的形状放置，其中 k 可以是任意大小。两个舰队之间至少有一个水平或垂直的空格分隔 （即没有相邻的舰队）。

int countBattleships(vector<vector<char>>& board) {
    if (board.empty()) return 0;
    int nr = board.size();
    int nc = board[0].size();
    int ret = 0;
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {
            if (board[i][j] == 'X') {
                board[i][j] = '.';
                for (int k = j + 1; k < nc && board[i][k] == 'X'; ++k) {
                    board[i][k] = '.';
                }
                for (int k = i + 1; k < nr && board[k][j] == 'X'; ++k) {
                    board[k][j] = '.';
                }
                ++ret;
            }
        }
    }
    return ret;
}
