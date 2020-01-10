/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (72.70%)
 * Likes:    677
 * Dislikes: 0
 * Total Accepted:    63K
 * Total Submissions: 86.7K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;

        dp.push_back(vector<string>{""});

        for(int i = 1; i <= n; ++i)
        {
            vector<string> tmp;
            for(int j = 0; j < i; ++j)
            {
                for(auto s1: dp[j])
                    for(auto s2: dp[i-1-j])
                        tmp.push_back(s1+"("+s2+")");
            }
            dp.push_back(tmp);
        }
        
        return dp[n];
    }
};
// @lc code=end

