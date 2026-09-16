// 437.路径总和III
//
// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

int dfs(TreeNode* root, long long target) {
    if (!root) return 0;
    int ret = 0;
    if (root->val == target) ret++;
    ret += dfs(root->left, target - root->val);
    ret += dfs(root->right, target - root->val);
    return ret;
}

int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;
    int ret = dfs(root, targetSum);
    ret += pathSum(root->left, targetSum);
    ret += pathSum(root->right, targetSum);
    return ret;
}

