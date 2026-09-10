// 19.删除链表的倒数第N个结点
//
// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *first = head, *second = dummy;
    for (int i = 0; i < n; ++i) {
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy->next;

}
