#include <lt_help/lt.h>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if( size <= 1 || ( k %= size ) == 0)
            return;
        _rotate(nums, 0, size, k);
    }

    void swap(vector<int>& nums, int i, int j){
        int x   = nums[i];
        nums[i] = nums[j];
        nums[j] = x;
    }

    void _rotate(vector<int>& nums, int pos, int n, int k){
        if( n <= 1 || k == 0 || n == k)
            return ;

        if( k <= n /2 )
        {   for( int i = 0; i < k; ++i)
                swap( nums, i + pos, i + pos + n - k);
            _rotate(nums, pos + k, n - k, k );
        }
        else
        {   for( int i = 0; i < n - k; ++i)
                swap( nums, i + pos, i + pos + k);
            _rotate(nums, pos , k, 2*k - n);
        }
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

