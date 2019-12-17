/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (33.29%)
 * Likes:    1531
 * Dislikes: 0
 * Total Accepted:    237.4K
 * Total Submissions: 713.1K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long rx = 0;
        do{
            rx *= 10;
            rx += (x%10);
            x /= 10;
        }while(x != 0);

        // cout << (1 << 30) << endl;

        if(rx > (1 << 31)-1 || rx < -1*(1 << 31))
            return 0;
        
        return rx;
    }
};
// @lc code=end

