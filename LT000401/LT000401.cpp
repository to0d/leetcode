#include <lt_help/lt.h>



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        if( size1 > size2 )
            return findMedianSortedArrays(nums2, nums1);     

        if( size2 == 0 )
            return 0;

        int l = 0, h = size1, half = (size1+size2+1)/2;
        while( l <= h )
        {
            int i = (l+h)/2;
            int j = half - i;

            if( i > 0 && nums1[i-1] > nums2[j])
                h = i - 1;
            else if ( i < size1 && nums2[j-1] > nums1[i] )
                l = i + 1;
            else
            {
                int max_left, min_right = 0 ;

                if ( i == 0 )
                    max_left = nums2[j-1];
                else if ( j == 0 )
                    max_left = nums1[i-1] ; 
                else
                    max_left = max(nums1[i-1], nums2[j-1]);

                if( (size1+size2)%2 == 1 )
                    return max_left;

                if (i == size1 )
                    min_right = nums2[j];
                else if (j == size2)
                    min_right = nums1[i];
                else
                    min_right = min(nums1[i], nums2[j]);

                return (max_left + min_right)/2.0;
            }            
        }

        return 0;       
    }
};


void test(vector<int> nums1, vector<int> nums2)
{
    cout << "input: nums1=";
    outputVector(nums1);
    cout << ", nums2=";
    outputVector(nums2);
    double r = Solution().findMedianSortedArrays(nums1, nums2);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({1, 2}, {3, 4});
}

// Result 
//
// 2023-02-08: Runtime 44ms 63.68% Memory 89.4MB 73.60%, https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/894118910/





