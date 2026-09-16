// 129.求根节点到叶节点
//
// 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
// 每条从根节点到叶节点的路径都代表一个数字：
// 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
// 计算从根节点到叶节点生成的 所有数字之和 。
// 叶节点 是指没有子节点的节点。


void dfs(int& sum, TreeNode* root, int num) {
    if (!root) return;
    num = num * 10 + root->val;
    if (!root->left && !root->right) {
        sum += num;
    }
    dfs(sum, root->left, num);
    dfs(sum, root->right, num);
}

int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    int ret = 0;
    dfs(ret, root, 0);
    return ret;
}

