#include <lt_help/lt.h>

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        vector<int> negative_nums;
        int sum = 0, minPositive = -1, maxNegative = 1;
        for(int v : nums )
            if( v < 0 )
            {   negative_nums.push_back(v);
                if( maxNegative == 1 )
                    maxNegative = v;
                else
                    maxNegative = std::max(maxNegative, v);
            }
            else
            {   sum += v;
                if( minPositive == -1 )
                    minPositive = v;
                else
                    minPositive = std::min(minPositive, v);
            }

       int negative_size = negative_nums.size();
       if( k < negative_size )
       {    // find the min negative number
           for(int j = 0; j < k ; ++j)
           {   for(int i = 1;i < negative_size - j; ++i)
                   if( negative_nums[i] > negative_nums[i-1] )
                   {    int v = negative_nums[i-1];
                        negative_nums[i-1] = negative_nums[i];
                        negative_nums[i] = v;
                   }
               negative_nums[negative_size-1-j] = -negative_nums[negative_size-1-j];
           }
           return sum + std::accumulate(negative_nums.begin(), negative_nums.end(), 0);
       }
       
       sum += - std::accumulate(negative_nums.begin(), negative_nums.end(), 0);
       k -= negative_size;
       if( k % 2 != 0 )
       {    int d1 = minPositive != -1 ? minPositive : INT_MAX;
           int d2 = maxNegative != 1 ? (-maxNegative) : INT_MAX;
           sum -= std::min(d1, d2)*2; 
       }

       return sum;
    }
};



void test(vector<int> nums, int k)
{
    cout << "input: k=" << k << ", nums=";
    outputVector(nums);
    int r = Solution().largestSumAfterKNegations(nums, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({4,2,3}, 1);
}


// Result 
//
// 2022-12-07: Runtime 13ms 16.84% Memory 9.2MB 35.26%, https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/submissions/856165372/
// 2023-02-19: Runtime 13ms 16.39% Memory 9.3MB 14.21%, https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/submissions/900664184/



