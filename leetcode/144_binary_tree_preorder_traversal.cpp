// 114.二叉树的前序遍历
//
// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

void preorder(TreeNode* root, vector<int>& ret) {
    if (!root) return;
    ret.push_back(root->val);
    preorder(root->left, ret);
    preorder(root->right, ret);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    preorder(root, ret);
    return ret;
}

