// 102.二叉树的层次遍历
//
// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (!root) return ret;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        int level = que.size();
        ret.push_back(vector<int>());
        for (int i = 1; i <= level; ++i) {
            TreeNode* node = que.front();
            que.pop();
            ret.back().push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
    }
    return ret;
}
