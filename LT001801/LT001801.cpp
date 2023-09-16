#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rst;
        std::sort(nums.begin(), nums.end(), std::less<int>());
        int size = nums.size();
        for(int i = 0; i < size - 3; ++i){
            if( i > 0 && nums[i] == nums[i-1] )
                continue;
            int a = nums[i];
            if( a > (long)target/4+1) // a+b+c+d = t ==> a <= t/4
                break;
            if( ((long)a + nums[size-3]  + nums[size-2] + nums[size-1]) < target )
                continue;
            if( ((long)a + nums[i+1] + nums[i+2] + nums[i+3]) > target )
                break;
            
            for(int j = i+1; j < size - 2; ++j){
                if( j > (i+1) && nums[j] == nums[j-1] )
                    continue;
                int b = nums[j];  // b+c+d = t-a ==> b <= (t-a)/3
                if( b > (long)(target-a)/3+1)
                    break;
                if( ((long)a + b + nums[size-2] + nums[size-1]) < target )
                    continue;
                if( ((long)a + b + nums[i+1] + nums[i+2]) > target )
                    break;
                
                for(int k = size-1; k > (j+1); --k){
                    if( k < (size-1) && nums[k] == nums[k+1] )
                        continue;
                    long d = nums[k];
                    if( d < ((long)target-a-b)/2 ) //  c+d = t-a-b ==> d > (t-a-b)/2
                        break;
                    long c = (long)target - a - b - d;
                    if (c < b || c > d )
                        continue;
                    int l = j+1, h = k - 1;
                    while(l <= h ) {   
                        int m = (l+h)/2, r = nums[m];
                        if( r == c ) {
                            rst.push_back({a, b, (int)c, (int)d});
                            break;
                        }
                        else if( r < c)
                            l = m + 1;
                        else 
                            h = m - 1;
                    }
                }
            }
        }       
        return rst; 
    }
};



void test(vector<int> nums, int target)
{
    cout << "input: target=" << target << ", nums=";
    outputVector(nums);
    vector<vector<int>> r = Solution().fourSum(nums, target);
    cout << "; output: ";
    outputVector(r);
    cout << endl;
}

int main(void)
{
    test({1,0,-1,0,-2,2}, 0);
}

// Result 
//
// 2023-09-16: Runtime 4ms 99.39% Memory 12.96MB 7.05%, https://leetcode.cn/problems/4sum/submissions/466690866/
