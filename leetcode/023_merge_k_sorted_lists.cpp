// 23.合并K个升序链表
//
// 给你一个链表数组，每个链表都已经按升序排列。
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。


ListNode* merge(ListNode* left, ListNode *right) {
    ListNode *dummy = new ListNode(0);
    ListNode *pre = dummy, *l1 = left, *l2 = right;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            pre->next = l1;
            l1 = l1->next;
        } else {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if (l1) pre->next = l1;
    if (l2) pre->next = l2;
    return dummy->next;
}

ListNode* mergeList(vector<ListNode*>& lists, int l, int r) {
    if (l > r) return nullptr;
    if (l == r) return lists[l];
    int mid = (l + r) / 2;
    return merge(mergeList(lists, l, mid), mergeList(lists, mid + 1, r));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return mergeList(lists, 0, lists.size() - 1); 
    
}

