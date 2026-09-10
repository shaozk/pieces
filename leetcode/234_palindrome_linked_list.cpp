// 234.回文链表
//
// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。


ListNode* reverse(ListNode* head) {
    ListNode *pre = nullptr, *cur = head;
    while (cur != nullptr) {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

ListNode* half(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr) return true;
    ListNode *first = half(head);
    ListNode *second = reverse(first->next);
    ListNode *p1 = head, *p2 = second;
    bool result = true;
    while (result && p2 != nullptr) {
        if (p1->val != p2->val) result = false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return result;
}

