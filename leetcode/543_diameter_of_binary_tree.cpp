// 543.二叉树的直径
//
// 给你一棵二叉树的根节点，返回该树的 直径 。
// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
// 两节点之间路径的 长度 由它们之间边数表示。

int ans = 1;
int depth(TreeNode* rt) {
    if (rt == NULL) return 0;
    int l = depth(rt->left);
    int r = depth(rt->right);
    ans = max(ans, l + r + 1);
    return max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    ans = 1;
    depth(root);
    return ans - 1;
}

