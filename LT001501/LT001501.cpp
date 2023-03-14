#include <lt_help/lt.h>

// a + b + c = 0
// a <= b <= c ==>  a <= 0
//                  c >= 0
// 
//       x1, x2, x3 ......    xn    <= ascending order numbers
//       |                    |
//  1)   v                    v
//       a                    c       
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rst;
        std::sort(nums.begin(), nums.end(), std::less<int>());
        int size = nums.size();
        int a,b,c, la, lc, last_a, last_c;
        for(la = 0, last_a = 1; la < size - 2 && (a = nums[la]) <= 0; ++la, last_a = a) // a must <= 0
        {   if( a == last_a )
                continue;
            for(lc = size - 1, last_c = -1; lc > la && (c = nums[lc]) >= 0; --lc, last_c = c) // c must >= 0
            {   if(c == last_c || la > lc-2 || (b =-a-c) < a || b > c)
                    continue;                   
                int l = la+1, h = lc-1;
                while(l <= h )  // binary search
                {   int m = (l+h)/2;
                    int r = nums[m];
                    if( r == b )
                    {   rst.push_back({a, b, c});
                        break;
                    }
                    else if( r < b)
                        l = m + 1;
                    else 
                        h = m - 1;
                }
            }      
        }
        return rst;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";  
    outputVector(nums); 
    auto r = Solution().threeSum(nums);
    cout << "; output: "; 
    outputVector(r); 
    cout << endl;
}

int main(void)
{
    test({-1,0,1,2,-1,-4});
}

// Result 
//
// 2022-11-03: Runtime 144ms 62.90% Memory 21.1MB 71.70%, https://leetcode.com/problems/3sum/submissions/836062856/
// 2023-02-15: Runtime 185ms 50.17% Memory 24.2MB 45.15%, https://leetcode.com/problems/3sum/submissions/898544342/
// 2023-03-13: Runtime 177ms 64.90% Memory 24.1MB 83.59%, https://leetcode.com/problems/3sum/submissions/914447893/



