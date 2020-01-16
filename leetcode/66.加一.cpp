/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.24%)
 * Likes:    403
 * Dislikes: 0
 * Total Accepted:    108.1K
 * Total Submissions: 254.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int dsize = digits.size();
        int tmp = 1;
        while(dsize--)
        {
            tmp += digits[dsize];
            if(tmp >= 10) {
                digits[dsize] = 0;
                tmp = 1;
            }
            else
            {
                digits[dsize] = tmp;
                tmp = 0;
                break;
            }
        }

        if(tmp)
        {
            auto it = digits.begin();
            digits.insert(it, tmp);
        }

        return digits;
    }
};
// @lc code=end

