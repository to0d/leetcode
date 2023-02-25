#include <lt_help/lt.h>



class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            
      vector<int> res; 
      
      sort( nums1.begin(), nums1.end());
      sort( nums2.begin(), nums2.end());
      int i = 0;
      int j = 0;
      
      while( i < nums1.size() && j < nums2.size() )
      {
          int a = nums1[i];
          int b = nums2[j];
          
          if( a < b )
            i++;
          else if( a > b )
            j++;
          else 
          { 
             res.push_back(a);
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
    vector<int> r = Solution().intersect(nums1, nums2);
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
// 2022-11-21: Runtime 3ms 93.98% Memory 10.1MB 60.19%, https://leetcode.com/problems/intersection-of-two-arrays-ii/submissions/847205652/

