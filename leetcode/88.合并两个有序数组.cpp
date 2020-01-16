/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (46.01%)
 * Likes:    386
 * Dislikes: 0
 * Total Accepted:    98.4K
 * Total Submissions: 213.2K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; ++i)
        {
            int left = 0;
            int right = m-1;
            int mid;
            while(left <= right)
            {
                mid = (left+right)/2;
                if(nums1[mid] > nums2[i])
                    right = mid-1;
                else 
                    left = mid+1;
            }

            for(int j = m; j > left; --j)
                nums1[j] = nums1[j-1];
            
            nums1[left] = nums2[i];
            m += 1;
        }
        
    }
};
// @lc code=end

