/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (49.34%)
 * Likes:    568
 * Dislikes: 0
 * Total Accepted:    84.1K
 * Total Submissions: 169.9K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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
    bool isSymmetricNode(TreeNode* p, TreeNode* q)
    {
        if(!p || !q)
            return p == q;
        return (p->val == q->val) && isSymmetricNode(p->left, q->right) && isSymmetricNode(p->right, q->left);
    }

public:
    // bool isSymmetric(TreeNode* root) {
    //     if (!root)
    //         return true;
        
    //     return isSymmetricNode(root->left, root->right);
    // }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        
        stack<TreeNode*> st;

        st.push(root->left);
        st.push(root->right);
        while(!st.empty())
        {
            auto n1 = st.top();
            st.pop();
            auto n2 = st.top();
            st.pop();

            if(n1 == nullptr && n2 == nullptr)
                continue;

            if(n1 && n2 && n1->val == n2->val)
            {
                st.push(n1->left);
                st.push(n2->right);
                st.push(n1->right);
                st.push(n2->left);
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

