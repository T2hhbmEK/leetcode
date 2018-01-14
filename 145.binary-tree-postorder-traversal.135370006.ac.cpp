/*
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (41.19%)
 * Total Accepted:    163.5K
 * Total Submissions: 396.9K
 * Testcase Example:  '[]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 
 * 
 * return [3,2,1].
 * 
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        for (int x: postorderTraversal(root->left)) {
            res.push_back(x);
        }
        for (int x: postorderTraversal(root->right)) {
            res.push_back(x);
        }
        res.push_back(root->val);
        return res;
    }
};
