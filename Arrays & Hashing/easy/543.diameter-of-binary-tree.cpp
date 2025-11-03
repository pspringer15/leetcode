/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.


Example 1:
    1
   / \
  2   3
 / \
4   5 
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100


Solution:

1) Custom Example:
        1
       / \
      2   3
         / \
        4   5
       /     \
      6       7
     /         \
    8           9

Output: 7 --> [8,6,4,3,5,7,9]

Must track length of every node's left subtree and right subtree
Length of path at any node is: |left| + |right| + 1
Must take max of those values --> can save memory by building it into tree
|---> Would be a clarifying question in interview
  

 */
#include <algorithm>

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
    void dfs(TreeNode* cur, int& max) {
        if (!cur) return;
        dfs(cur->left, max);
        dfs(cur->right, max);
        cur->val = 1;
        if (cur->left && cur->right) {
            cur->val += std::max(cur->left->val, cur->right->val);
        } else if (cur->left && !cur->right) {
            cur->val += cur->left->val;
        } else if (cur->right && !cur->left) {
            cur->val += cur->right->val;
        }
        if (cur->val > max) max = cur->val;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
    }
};
// @lc code=end

