// 113.路径总和II
//
// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
// 叶子节点 是指没有子节点的节点。

void dfs(vector<vector<int>>& vec, vector<int>& path, TreeNode* root, int target) {
    if (!root) return;
    path.push_back(root->val);
    target -= root->val;
    if (!root->left && !root->right && target == 0) {
        vec.push_back(path);
    }
    dfs(vec, path, root->left, target);
    dfs(vec, path, root->right, target);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ret;
    vector<int> path;
    dfs(ret, path, root, targetSum);
    return ret;
}

