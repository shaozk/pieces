// 98.验证二叉搜索树
//
// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
// 有效 二叉搜索树定义如下：
// 节点的左子树只包含 严格小于 当前节点的数。
// 节点的右子树只包含 严格大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。

bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stk;
    long long inorder = (long long)INT_MIN - 1;
    while (!stk.empty() || root != nullptr) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (root->val <= inorder) return false;
        inorder = root->val;
        root = root->right;
    }
    return true;
}


