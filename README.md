# Count Good Nodes in Binary Tree

## Problem Statement
Given a binary tree, a node is considered **good** if in the path from the root to that node, there are no nodes with a value greater than the node’s value.  
Return the number of good nodes in the binary tree.

This is LeetCode Problem [1448. Count Good Nodes in Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree).

---

## Approach
- Perform a **DFS traversal** of the tree.
- Carry along the maximum value seen so far (`mx`) from the root to the current node.
- If the current node’s value is greater than or equal to `mx`, it is a good node.
- Update `mx` with the current node’s value and continue recursively for left and right children.
- Count all such good nodes.

---

## Complexity Analysis
- **Time Complexity:** `O(N)`  
  Each node is visited once, where `N` is the number of nodes in the tree.
- **Space Complexity:** `O(H)`  
  Recursion stack depends on the height of the tree (`H`). In the worst case (skewed tree), `H = N`.

---

## Code Implementation (C++)
```cpp
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
 */
class Solution {
public:
    int cnt = 0;

    void maxpath(TreeNode* root, int mx) {
        if (root == nullptr) return;

        if (root->val >= mx) cnt++;
        mx = max(mx, root->val);

        maxpath(root->left, mx);
        maxpath(root->right, mx);
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        maxpath(root, INT_MIN);  // start with the smallest possible value
        return cnt;
    }
};
