/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (53.81%)
 * Likes:    376
 * Dislikes: 0
 * Total Accepted:    67.1K
 * Total Submissions: 124.1K
 * Testcase Example:  '1'
 *
 * 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
 * 
 * 注意：整数序列中的每一项将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp;
        dp.push_back("");
        dp.push_back("1");
        for(int i = 2; i <= n; ++i)
        {
            string &ls = dp[i-1];
            string s;
            char lc = ls[0];
            int count = 0;
            for(int j = 0; j < ls.size(); ++j)
            {
                if(ls[j] == lc)
                    ++count;
                else
                {
                    s.push_back(count+'0');
                    s.push_back(lc);
                    lc = ls[j];
                    count = 1;
                }
            }
            s.push_back(count+'0');
            s.push_back(lc);
            dp.push_back(s);
        }

        return dp[n];
    }
};
// @lc code=end

