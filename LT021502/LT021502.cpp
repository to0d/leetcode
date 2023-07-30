#include <lt_help/lt.h>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pos = 0, n = nums.size();
        while( n > 0)
        {   int target = nums[pos];
            if( k == 1 )                        // find the largest number
            {   for(int i = 1; i < n; ++i )
                    target = std::max(nums[pos+i],target );
                return target;
            }
            else if( k == n )                   // find the smallest number
            {   for( int i = 1; i < n; ++i )
                    target = std::min(nums[pos+i],target );
                return target;
            }

            int low = 1, high = n-1;
            while( low <= high )
            {   if( nums[pos+low] >= target )
                    ++low;
                else if( nums[pos+high] < target )
                    --high;
                else                            // swap numbers
                {   int t = nums[pos+low];
                    nums[pos+low] = nums[pos+high];
                    nums[pos+high] = t;
                }
            }

            // a[0]  .. bigger .... smaller ....
            //  1        low        high
            if( k <= high )
            {   pos++;
                n = high;
            }
            else if( k == (high+1) )
                return target;  
            else
            {   pos += low;
                n   -= high+1;
                k   -= high+1;
            }
        }
        return 0;
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
// 2022-11-21: Runtime 135ms 49.63% Memory 11.2MB 91.24%, https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/847520326/
// 2023-07-30: Runtime 60ms 95.42% Memory 43.29MB 92.16%, https://leetcode.cn/problems/kth-largest-element-in-an-array/submissions/451542681/

