/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (42.41%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    63.1K
 * Total Submissions: 148.9K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int ssize = nums.size();
        sort(nums.begin(), nums.end());

        int retsum = nums[0]+nums[1]+nums[2];
        int diff = abs(retsum-target);


        for(int i = 0; i < ssize-2; ++i)
        {
            int left = i+1;
            int right = ssize-1;
            while(left < right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                int tmpdiff = abs(sum-target);
                if(tmpdiff < diff)
                {
                    retsum = sum;
                    diff = tmpdiff;
                }
                
                if(sum > target)
                    right--;
                if(sum < target)
                    left++;
                if(sum == target)
                    return retsum;
            }
        }
        
        return retsum;
    }
};
// @lc code=end

