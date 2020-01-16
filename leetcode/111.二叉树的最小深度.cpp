/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (40.80%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    45.3K
 * Total Submissions: 110.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
 * 
 */

// @lc code=start
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
private:
    int nodeMinDepth(TreeNode* node)
    {
        if(!node)
        {
            return INT32_MAX;
        }
        else if(!node->left && !node->right)
        {
            return 1;
        }
        else
        {
            return min(nodeMinDepth(node->left), nodeMinDepth(node->right))+1;
        }
    }
public:
    // int minDepth(TreeNode* root) {
    //     return root? nodeMinDepth(root): 0;
    // }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        return (l&&r? min(l,r): max(l,r))+1;
    }
};
// @lc code=end

