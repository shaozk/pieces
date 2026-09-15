// 199.二叉树的右视图
//
// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

vector<int> ret;

void dfs(TreeNode* root, int depth) {
    if (!root) return;
    if (depth == ret.size()) ret.push_back(root->val);
    dfs(root->right, depth + 1);
    dfs(root->left, depth + 1);
}
vector<int> rightSideView(TreeNode* root) {
    dfs(root, 0);
    return ret;
}
