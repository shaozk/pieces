// 226.翻转二叉树
//
// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。


bool check(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;    
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
    return check(root->left, root->right);
}
