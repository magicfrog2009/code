/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (68.13%)
 * Likes:    301
 * Dislikes: 0
 * Total Accepted:    43.8K
 * Total Submissions: 63.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
private:
    TreeNode* makeNode(vector<int>& nums, int left, int right)
    {
        if(left == right)
            return new TreeNode(nums[left]);

        int mid = (left+right)/2;
        TreeNode* node = new TreeNode(nums[mid]);

        if(left < mid)
            node->left = makeNode(nums, left, mid-1);
        if(right > mid)
            node->right = makeNode(nums, mid+1, right);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return nums.empty()? nullptr :makeNode(nums, 0, nums.size()-1);
        
    }
};
// @lc code=end

