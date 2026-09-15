// 230.二叉搜索树中的第K小的元素
//
// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（k 从 1 开始计数）。

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        --k;
        if (k == 0) break;
        root = root->right;
    }
    return root->val;
    
}

