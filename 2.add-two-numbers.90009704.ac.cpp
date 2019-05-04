/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers
 *
 * Medium (27.29%)
 * Total Accepted:    287846
 * Total Submissions: 1054815
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode r(0), *cur = &r;
        int carry = 0;
        while (l1 || l2 || carry) {
            int val = (l1? l1->val:0) + (l2? l2->val:0) + carry;
            cur->next = new ListNode(val % 10);
            carry = val/10;
            l1 = l1? l1->next:l1;
            l2 = l2? l2->next:l2;
            cur=cur->next;
        }
        return r.next;
    }
};
