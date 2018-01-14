/*
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (24.42%)
 * Total Accepted:    127.2K
 * Total Submissions: 521.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * 
 * 
 * Example:
 * 
 * Given 1->2->3->4->5->NULL and k = 2,
 * 
 * return 4->5->1->2->3->NULL.
 * 
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        int cnt = 0;
        ListNode *p = NULL, *f = NULL;
        for (p = head; p != NULL; p = p->next) {
            f = p;
            cnt++;
        }
        f->next = head;
        p = head;
        for (int i = 0; i < cnt-(k%cnt); i++) {
            f = p;
            p = p->next;
        }
        f->next = NULL;
        return p;
    }
};
