/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (51.65%)
 * Likes:    285
 * Dislikes: 0
 * Total Accepted:    56.8K
 * Total Submissions: 109.5K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int asize = a.size();
        int bsize = b.size();

        string& target = asize < bsize ? b: a;
        string& left = asize >= bsize ? b: a;
        int tsize = target.size();
        int lsize = left.size();
        int tmp = 0;

        while(lsize-- && tsize--)
        {
            tmp += (left[lsize]-'0');
            tmp += (target[tsize]-'0');
            if(tmp == 0 || tmp == 2)
                target[tsize] = '0';
            else
                target[tsize] = '1';

            if(tmp >= 2)
                tmp = 1;
            else 
                tmp = 0;
        }

        while(tsize--)
        {
            tmp += (target[tsize]-'0');
            if(tmp > 1)
            {
                target[tsize] = '0';
                tmp = 1;
            }
            else
            {
                target[tsize] = (tmp + '0');
                tmp = 0;
            }
            
        }

        if(tmp)
        {
            auto it = target.begin();
            target.insert(it, '1');
        }

        return target;        
    }
};
// @lc code=end

