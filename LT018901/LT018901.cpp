#include <lt_help/lt.h>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if( size <= 1 || ( k %= size ) == 0)
            return;
        
        int pos = 0, n = size, kk = k;
        while(n > 1 && kk > 0 && kk < n)
        {   if( kk <= n /2 )
            {   for( int i = 0; i < kk; ++i)
                    swap( nums, i + pos, i + pos + n - kk);
                pos += kk;
                n   -= kk;
            }
            else
            {   for( int i = 0; i < n - kk; ++i)
                    swap( nums, i + pos, i + pos + kk);
                int m = n;
                n    = kk;
                kk   = 2*kk - m;
            }
        }
    }

    inline void swap(vector<int>& nums, int i, int j){
        int x   = nums[i];
        nums[i] = nums[j];
        nums[j] = x;
    }
};


void test(vector<int> nums, int k)
{
    cout << "input: k=" << k <<", nums=";  
    outputVector(nums); 
    Solution().rotate(nums, k);
    cout << "; output: ";
    outputVector(nums); 
    cout << ";" << endl;
}


int main(void)
{
    test({1,2,3,4,5,6,7}, 3);
}

// Result 
//
// 2022-11-19: Runtime 100ms 5.4% Memory 25MB 85.19%, https://leetcode.com/problems/rotate-array/submissions/846349061/
// 2023-02-19: Runtime 34ms 60.42% Memory 25MB 85.24%, https://leetcode.com/problems/rotate-array/submissions/900671353/
// 2023-07-28: Runtime 24ms 73.32% Memory 23.72MB 83.48%, https://leetcode.cn/problems/rotate-array/submissions/451129641/

