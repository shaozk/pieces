// 206.反转列表
//
// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *cur = head;
    while (cur != nullptr) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

