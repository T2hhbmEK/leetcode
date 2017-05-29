/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs
 *
 * Medium (37.89%)
 * Total Accepted:    159423
 * Total Submissions: 420797
 * Testcase Example:  '[]'
 *
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * 
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 * 
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p1, *p4, l0(0);
        l0.next = head;
        if (head == NULL || head->next == NULL) return l0.next;
        p1 = &l0;
        while (true) {
            ListNode *tmp1, *tmp2;
            tmp1 = p1->next;
            tmp2 = tmp1->next;
            p4 = tmp2->next;
            p1->next = tmp2;
            tmp2->next = tmp1;
            tmp1->next = p4;
            if (p4!=NULL && p4->next!=NULL) {
                p1 = tmp1;
            } else break;
        }
        return l0.next;
    }
};
