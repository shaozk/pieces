// 21.合并两个有序链表
//
// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *l1 = list1, *l2 = list2;
    ListNode *dummy = new ListNode(0);
    ListNode *pre = dummy;
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

