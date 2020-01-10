/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.44%)
 * Likes:    351
 * Dislikes: 0
 * Total Accepted:    47.3K
 * Total Submissions: 129.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int ssize = nums.size();
        vector<vector<int>> sets;

        sort(nums.begin(), nums.end());

        int i = 0;
        while (i <= ssize-4)
        {
            int first = nums[i];
            int subfirst = target-first;

            int j = i+1;
            while (j <= ssize-3)
            {
                int second = nums[j];
                int subsecond = subfirst-second;

                int left = j+1;
                int right = ssize-1;
                while(left < right)
                {
                    int sum = nums[left]+nums[right];
                    if(sum == subsecond)
                    {
                        sets.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});

                        int leftval = nums[left];
                        while(left < right && leftval == nums[left])
                            ++left;

                        int rightval = nums[right];
                        while(left < right && rightval == nums[right])
                            --right;
                    }
                    else if(sum > subsecond)
                    {
                        --right;
                    }
                    else
                    {
                        ++left;
                    }
                }

                // skip the repeat numbers
                while (j <= ssize-3 && second == nums[j])
                    ++j;
            }

            // skip the repeat numbers
            while (i <= ssize-4 && first == nums[i])
                ++i;
        }

        return sets;
    }
};
// @lc code=end

