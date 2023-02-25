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
        vector<vector<int>> result;
        int la = 0,lc,a,b,c;

        std::sort(nums.begin(), nums.end(), std::less<int>());

        for(int ax = 1; la < (int)nums.size() - 2 && (a = nums[la]) <= 0; ++la, ax = a)
        {   if( a == ax )
                continue;

            lc = (int)nums.size() - 1;
            for(int cx = -1; lc >= 2 && (c = nums[lc]) >= 0; --lc, cx = c)
            {
                if(c == cx || la > lc-2 || (b =-a-c) < a || b > c)
                    continue;                   

                int l = la+1, h = lc-1;
                while(l <= h )  // binary search
                {   
                    int m = (l+h)/2;
                    int r = nums[m];
                    if( r == b )
                    {   result.push_back({a, b, c});
                        break;
                    }
                    else if( r < b)
                        l = m + 1;
                    else 
                        h = m - 1;
                }
            }      
        }

        return result;
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


