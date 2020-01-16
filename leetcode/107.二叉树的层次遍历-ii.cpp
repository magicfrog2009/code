/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (63.50%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    37K
 * Total Submissions: 58.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        if(root == nullptr)
            return res;

        queue<TreeNode*> v1;
        queue<TreeNode*> v2;
        v1.push(root);

        while (true)
        {
            vector<int> t1;
            while(!v1.empty())
            {
                auto it = v1.front();
                v1.pop();
                t1.push_back(it->val);
                if(it->left)
                    v2.push(it->left);
                if(it->right)
                    v2.push(it->right);
            }
            res.push_back(t1);
            if(v2.empty())
                break;

            t1.resize(0);
            while (!v2.empty())
            {
                auto it = v2.front();
                v2.pop();
                t1.push_back(it->val);
                if(it->left)
                    v1.push(it->left);
                if(it->right)
                    v1.push(it->right);
            }
            res.push_back(t1);
            if(v1.empty())
                break;
        }

        reverse(res.begin(), res.end());
        
        return res;
    }
};
// @lc code=end

