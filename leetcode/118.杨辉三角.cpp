/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (65.05%)
 * Likes:    224
 * Dislikes: 0
 * Total Accepted:    53.9K
 * Total Submissions: 82.6K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)
            return res;
        if(numRows >= 1)
            res.push_back(vector<int>{1});
        if(numRows >= 2)
            res.push_back(vector<int>{1,1});

        for(int i = 3; i <= numRows; ++i)
        {
            vector<int> v;
            v.push_back(1);
            vector<int>& up = res.back();
            for(int j = 0; j < up.size()-1; ++j)
            {
                v.push_back(up[j]+up[j+1]);
            }
            v.push_back(1);
            res.push_back(v);
        }
        
        return res;
    }
};
// @lc code=end

