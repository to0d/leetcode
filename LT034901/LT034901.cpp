#include <lt_help/lt.h>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort( nums1.begin(), nums1.end());
        auto pos1 = unique(nums1.begin(), nums1.end());
        nums1.erase(pos1, nums1.end());

        sort( nums2.begin(), nums2.end());
        auto pos2 = unique(nums2.begin(), nums2.end());
        nums2.erase(pos2, nums2.end());

        vector<int> res;
        int i = 0, j = 0, size1 = nums1.size(), size2 = nums2.size();
        while( i < size1 && j < size2 )
        {   int a = nums1[i], b = nums2[j];
            if( a < b )
                i++;
            else if( a > b )
                j++;
            else 
            {   res.push_back(a);
                ++i;
                ++j;
            }                  
        }
        return res;
    }
};


            
void test(vector<int> nums1, vector<int> nums2)
{
    cout << "input: nums1=";
    outputVector(nums1);
    cout << ", nums2=";
    outputVector(nums2);
    vector<int> r = Solution().intersection(nums1, nums2);
    cout << "; output: "; 
    outputVector(r);
    cout << endl;
}


int main(void)
{
    test({4,9,5}, {9,4,9,8,4});
}

// Result 
//
// 2022-11-21: Runtime 13ms 27.71% Memory 10MB 92.62%, https://leetcode.com/problems/intersection-of-two-arrays/submissions/847204664/
// 2023-02-22: Runtime 5ms 75.69% Memory 9.9MB 92.61%, https://leetcode.com/problems/intersection-of-two-arrays/submissions/902941149/




