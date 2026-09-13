// 148.排序链表
//
// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。


ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *n1 = l1, *n2 = l2;
    ListNode *pre = dummy;
    while (n1 && n2) {
        if (n1->val < n2->val) {
            pre->next = n1;
            n1 = n1->next;
        } else {
            pre->next = n2;
            n2 = n2->next;
        }
        pre = pre->next;
    }
    if (n1) pre->next = n1;
    if (n2) pre->next = n2;
    return dummy->next;
}

ListNode* sortList(ListNode* head, ListNode* tail) {
    if (head == nullptr) return head;
    if (head->next == tail) {
        head->next = nullptr;
        return head;
    }
    ListNode *slow = head, *fast = head;
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) fast = fast->next;
    }
    ListNode *mid = slow;
    return merge(sortList(head, mid), sortList(mid, tail));
}

ListNode* sortList(ListNode* head) {
    return sortList(head, nullptr);
}

