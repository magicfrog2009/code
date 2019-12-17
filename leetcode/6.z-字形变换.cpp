/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (45.85%)
 * Likes:    484
 * Dislikes: 0
 * Total Accepted:    79.4K
 * Total Submissions: 173.1K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1)
            return s;

        const int ssize = s.size();
        int layer = 0;
        string sz;

        int inc = (numRows-1)*2;

        while(layer < numRows)
        {
            // first and last row
            if(layer == 0 || layer == numRows-1)
            {
                for(int i = layer; i < ssize; i+= inc)
                    sz.push_back(s[i]);
            }
            else
            {
                for(int i = layer, j = 2*(numRows-1)-layer; i < ssize; i += inc, j+= inc)
                {
                    sz.push_back(s[i]);
                    if(j < ssize)
                        sz.push_back(s[j]);
                }
            }

            layer++;
            
        }

        return sz;        
    }

};
// @lc code=end

