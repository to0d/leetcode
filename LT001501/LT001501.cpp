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
        for(int i = 0; i < size - 2; ++i){
            if( i > 0 && nums[i] == nums[i-1] )
                continue;
            int a = nums[i];
            if( a > 0 ) // a must <= 0
                break;
            if( (a + nums[size-2] + nums[size-1]) < 0 )
                continue;
            if( (a + nums[i+1] + nums[i+2]) > 0 )
                break;
            for(int j = size-1; j > (i+1) ; --j){
                if( j < (size-1) && nums[j] == nums[j+1] )
                    continue;
                int c = nums[j];
                if( c < 0 ) // c must >= 0
                    break;
                int b = 0 - a - c;
                if (b < a || b > c )
                    continue;
                int l = i+1, h = j - 1;
                while(l <= h ) {   
                    int m = (l+h)/2, r = nums[m];
                    if( r == b ) {
                        rst.push_back({a, b, c});
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
// 2023-09-16: Runtime 168ms 26.82% Memory 23.1MB 19.18%, https://leetcode.cn/problems/3sum/submissions/466685247/



