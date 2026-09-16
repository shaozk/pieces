// 105.从前序与中序遍历序列构造二叉树
//
// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

unordered_map<int, int> index; 

TreeNode* tree(vector<int>& pre, vector<int>& in, int pl, int pr, int il, int ir) {
    if (pl > pr) return nullptr;
    int pt = pl;
    int it = index[pre[pt]];
    TreeNode* root = new TreeNode(pre[pt]);
    int sub_len = it - il;
    root->left = tree(pre, in, pl + 1, pl + sub_len, il, it - 1);
    root->right = tree(pre, in, pl + sub_len + 1, pr, it + 1, ir);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    for (int i = 0; i < n; ++i) {
        index[inorder[i]] = i;
    }
    return tree(preorder, inorder, 0, n - 1, 0, n - 1);
}
