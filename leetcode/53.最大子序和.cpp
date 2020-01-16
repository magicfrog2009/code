/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.48%)
 * Likes:    1489
 * Dislikes: 0
 * Total Accepted:    143.2K
 * Total Submissions: 294.5K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        const int nsize = nums.size();
        int sum = 0;
        int res=INT32_MIN;
        for(int i = 0 ; i < nsize; ++i)
        {
            sum += nums[i];
            if(sum < nums[i])
                sum = nums[i];
            res = max(res, sum);
        }

        return res;  
    }
};
// @lc code=end

