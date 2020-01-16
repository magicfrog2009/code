/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (19.01%)
 * Likes:    247
 * Dislikes: 0
 * Total Accepted:    30.9K
 * Total Submissions: 162.6K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 
 * 说明:
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)
            return INT32_MAX;
        if(dividend == 0)
            return 0;

        if(dividend == INT32_MIN && divisor == 1)
            return INT32_MIN;

        long ldividend=labs(dividend);
        long ldivisor=labs(divisor);
     
        long res = exp(log(ldividend)-log(ldivisor));

        if(res > INT32_MAX)
            return INT32_MAX;

        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            return res;
        else 
            return -res;
        
    }
};
// @lc code=end

