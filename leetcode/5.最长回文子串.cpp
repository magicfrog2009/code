/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.79%)
 * Likes:    1544
 * Dislikes: 0
 * Total Accepted:    151.8K
 * Total Submissions: 546.2K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.size();
        int max = 1;
        int index = 0;
        for(int i=0; i< slen-max/2; ++i)
        {
            // bb check
            int m = 1;
            while((i+m) <= (slen-1) && (i-m+1)>= 0)
            {
                if(s[i-m+1] == s[i+m])
                    ++m;
                else
                {
                    break;
                }
                
            }

            if(2*(m-1) > max)
            {
                max = 2*(m-1);
                index = i;
            }
            
            // bab check
            m = 1;
            while((i+m) <= (slen-1) && (i-m)>= 0)
            {
                if(s[i+m] == s[i-m])
                    ++m;
                else
                {
                    break;
                }
                
            }

            if(2*(m-1)+1 > max)
            {
                max = 2*(m-1)+1;
                index = i;
            }
        }

        return s.substr(index-(max-1)/2, max);

    }
};
// @lc code=end

