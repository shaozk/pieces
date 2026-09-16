// 257.二叉树的所有路径
//
// 给你一个二叉树的根节点 root。
// 按 任意顺序 ，返回所有 从根节点到叶子节点 的路径。
// 叶子节点 是指没有子节点的节点。


void dfs(vector<string>& ret, TreeNode* root, string path) {
    if (!root) return;
    path += to_string(root->val);
    if (!root->left && !root->right) {
        ret.push_back(path);
    } else {
        path += "->";
        dfs(ret, root->left, path);
        dfs(ret, root->right, path);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    dfs(ret, root, "");
    return ret;
}
