#include <lt_help/lt.h>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1, i = m - 1, j = n - 1;
        while( j >= 0 )
        {   if( i >= 0 && nums1[i] > nums2[j] )
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};


void test(vector<int> nums1, int m, vector<int> nums2, int n)
{
    cout << "input: m=" << m << ", nums1="; 
    outputVector(nums1);
    cout << ", n=" << n << ", nums2="; 
    outputVector(nums2);    
    cout << "; output: ";
    Solution().merge(nums1, m, nums2, n);
    outputVector(nums1); 
    cout << ";" << endl;
}

int main(void)
{
    test({1,2,3,0,0,0}, 3, {2,5,6}, 3);
}

// Result 
//
// 2022-11-06: Runtime 6ms 44.72% Memory 6MB 98.74%, https://leetcode.com/problems/merge-sorted-array/submissions/855109300/
// 2023-02-27: Runtime 3ms 67.68% Memory 9.2MB 35.95%, https://leetcode.com/problems/merge-sorted-array/submissions/905715364/


