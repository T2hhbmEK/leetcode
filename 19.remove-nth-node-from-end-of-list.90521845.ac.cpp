/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list
 *
 * Medium (32.92%)
 * Total Accepted:    173200
 * Total Submissions: 526085
 * Testcase Example:  '[1]\n1'
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 * 
 * 
 * For example,
 * 
 * 
 * ⁠  Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * ⁠  After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nextToRemove = head, *last = head, *tmp = NULL;
        for(;last->next != NULL && n > 0;n--) {
            last = last->next;
        }
        while(last->next != NULL) {
            nextToRemove = nextToRemove->next;
            last = last->next;
        }
        if (n == 1) {
            tmp = head;
            head = tmp->next;
            delete tmp;
        }
        if (n == 0) {
            tmp = nextToRemove->next;
            nextToRemove->next = tmp->next;
            delete tmp;
        }
        return head;
    }
};
