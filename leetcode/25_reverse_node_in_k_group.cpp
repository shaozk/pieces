// 25.K个一组翻转链表
//
// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。


pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
    ListNode *pre = nullptr, *cur = head;
    while (pre != tail) {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return {tail, head};
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *pre = dummy, *cur = dummy->next;
    while (cur) {
        ListNode *tail = pre;
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
            if (!tail) return dummy->next;
        }
        ListNode *tmp = tail->next;
        auto result = reverse(cur, tail);
        cur = result.first;
        tail = result.second;

        pre->next = cur; 
        tail->next = tmp;
        pre = tail;
        cur = tail->next;
    }
    return dummy->next;
}

