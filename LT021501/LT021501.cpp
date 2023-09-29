#include <lt_help/lt.h>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int min_val = -10000, max_len = 20001;
        vector<int> vec(max_len, 0);
        int max_val = INT_MIN;
        for( int num : nums ){
            vec[num-min_val]++;
            max_val = max(max_val, num);
        }

        for( int val = max_val; val >= min_val; --val )
            if( vec[val-min_val] > 0){
                k -= vec[val-min_val];
                if(k <= 0)
                    return val;
            }
        return -1;
    }
};


   
void test(vector<int> nums, int k)
{
    cout << "input: nums=";
    outputVector(nums);
    cout << ", k=" << k;
    int r = Solution().findKthLargest(nums, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({3,2,1,5,6,4}, 2);
}

// Result 
//
// 2022-11-21: Runtime 317ms 5.2% Memory 47.3MB 33.85%, https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/847518374/
// 2023-03-12: Runtime 154ms 21.39% Memory 47.4MB 34.8%, https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/913852520/
// 2023-09-27: Runtime 92ms 72.81% Memory 58.3MB 7.45%, https://leetcode.cn/problems/kth-largest-element-in-an-array/submissions/469955148/

