// 988.从叶结点开始的最小字符串
//
// 给定一颗根结点为 root 的二叉树，树中的每一个结点都有一个 [0, 25] 范围内的值，分别代表字母 'a' 到 'z'。
// 返回 按字典序最小 的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束。
// 注：字符串中任何较短的前缀在 字典序上 都是 较小 的：
// 例如，在字典序上 "ab" 比 "aba" 要小。叶结点是指没有子结点的结点。 
// 节点的叶节点是没有子节点的节点。


void dfs(string& small, TreeNode* root, string path) {
    if (!root) return;
    path = char(root->val + 'a') + path;
    if (!root->left && !root->right) {
        if (small.empty() || small > path) {
            small = path;
        }
    } 
    dfs(small, root->left, path);
    dfs(small, root->right, path);
}

string smallestFromLeaf(TreeNode* root) {
    if (!root) return "";
    string small = "";
    dfs(small, root, "");
    return small;
}
