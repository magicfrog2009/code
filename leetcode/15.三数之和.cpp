/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.83%)
 * Likes:    1642
 * Dislikes: 0
 * Total Accepted:    134.4K
 * Total Submissions: 541K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sets;
        const int nsize = nums.size();
        if(nsize < 3)
            return sets;

        // sort
        sort(nums.begin(), nums.end());

        if(nums[0] > 0 || nums[nsize-1] < 0)
            return sets;

        long int first = nums[0] - 1;
        for(int i = 0; i < nsize; ++i)
        {
            if (first == nums[i])
                continue;
                
            if(nums[i] > 0)
                break;

            first = nums[i];

            long int second = first - 1;
            int lastk = nsize-1;
            for(int j = i+1; j < lastk; ++j)
            {
                if (second == nums[j])
                    continue;
                second = nums[j];

                int left = 0-first-second;
                for(int k = lastk; k > j; --k)
                {
                    if(nums[k] <= left)
                    {
                        if(nums[k] == left)
                            sets.push_back({first, second, left});

                        lastk = k;
                        break;
                    }
                }
            }
        }

        return sets;
    }
};

// @lc code=end

