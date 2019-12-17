/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m < n)
            return retmid(nums1, m, nums2, n);
        else 
            return retmid(nums2, n, nums1, m);

    }

private:
    double retmid(vector<int>& A, int na, vector<int>& B, int nb)
    {
        int sum = na + nb;
        int half = sum/2+1;
        int i, j;
        

        for(i = 1; i <= na; ++i)
        {
            j = half - i;
            int left = j-2 >= 0 ? j-2: 0;
            int right = j < nb ? j: nb-1;
            if((A[i-1] >= B[left] && A[i-1] <= B[right]) || A[i-1] >= B[right])
                break;
        }

        if(i > na)
            i = na;

        if(sum & 0x1)
        {
            return A[i-1] > B[j-1]? A[i-1]: B[j-1];
        }
        else
        {
            if(j-2 >= 0)
            {
                return (B[j-2]+B[j-1])/2.0f;
            }
            else
                return (A[i-1] + B[j-1])/2.0f;
        }
    }
};
// @lc code=end

