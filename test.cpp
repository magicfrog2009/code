#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdint>


using namespace std;

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

int main(int argc, char** argv)
{
    vector<int> a({1,2,3,0,0,0});
    vector<int> b({2,3,5});
    Solution s;
    s.merge(a, 3, b, 3);
    // cout << c << endl;

    return 0;
}