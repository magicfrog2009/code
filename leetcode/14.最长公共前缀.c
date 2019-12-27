/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.58%)
 * Likes:    811
 * Dislikes: 0
 * Total Accepted:    164.1K
 * Total Submissions: 461.1K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start


char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0 || strs == NULL)
        return "";
        
    int slen = strlen(strs[0]);
    int i = 0;
    for(; i < slen; ++i)
    {
        int j = 1;
        for(; j < strsSize; ++j)
        {
            if(strs[j][i] != strs[0][i])
                break;
        }

        if(j != strsSize)
            break;
    }
    
    if (i == 0)
        return "";
    else
    {
        strs[0][i] = '\0';
        return strs[0];
    }
}


// @lc code=end

