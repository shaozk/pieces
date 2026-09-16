// 124.二叉树的最大路径和
//
// 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
// 路径和 是路径中各节点值的总和。
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

int dfs(int& sum, TreeNode* root) {
    if (!root) return 0;
    int left = max(dfs(sum, root->left), 0);
    int right = max(dfs(sum, root->right), 0);
    int path = root->val + left + right;

    sum = max(sum, path);
    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    int ret = INT_MIN;
    dfs(ret, root);
    return ret;
}

