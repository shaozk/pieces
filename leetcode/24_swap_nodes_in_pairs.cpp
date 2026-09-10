// 24.两两交换链表中的节点
//
// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

ListNode* swapPairs(ListNode* head) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *pre = dummy;
    while (pre->next && pre->next->next) {
        ListNode *no1 = pre->next;
        ListNode *no2 = pre->next->next;
        pre->next = no2;
        no1->next = no2->next;
        no2->next = no1;
        pre = no1;
    }
    return dummy->next;
    
}

