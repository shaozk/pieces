// 114.二叉树展开为链表
//
// 给你二叉树的根结点 root ，请你将它展开为一个单链表：
// * 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
// * 展开后的单链表应该与二叉树 先序遍历 顺序相同。


void flatten(TreeNode* root) {
    if (!root) return;
    TreeNode* cur = root;
    while (cur) {
        if (cur->left) {
            TreeNode *best = cur->left;
            while (best->right) {
                best = best->right;
            }
            best->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}
