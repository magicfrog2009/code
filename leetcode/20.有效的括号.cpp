/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.33%)
 * Likes:    1291
 * Dislikes: 0
 * Total Accepted:    176.5K
 * Total Submissions: 437.4K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start

#include <stack>
class Solution {
private:
    static inline char cvalue(char c)
    {
        if(c == '{')
            return 1;
        if(c == '[')
            return 1;
        if(c == '(')
            return 1;
    
        return 0;
    }

    static inline bool cmatch(char c1, char c2)
    {
        if(c1 == '(' && c2 == ')')
            return true;
        if(c1 == '[' && c2 == ']')
            return true;
        if(c1 == '{' && c2 == '}')
            return true;
        
        return false;
    }

public:
    bool isValid(string s) {
        stack<char> Sc;

        if(s.empty())
            return true;

        for(auto& c: s)
        {
            if(c == '{' || c == '[' || c == '(')
            {
                Sc.push(c);

                // if(Sc.empty())
                //     Sc.push(c);
                // else
                // {
                //     auto lc = Sc.top();

                //     if(cvalue(lc) < cvalue(c))
                //         return false;
                //     else 
                //         Sc.push(c);
                // }
            }
            else
            {
                if(Sc.empty())
                    return false;
                else
                {
                    auto lc = Sc.top();
                    if(cmatch(lc, c) || cmatch(c, lc))
                    {
                        Sc.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return Sc.empty();        
    }
};
// @lc code=end

