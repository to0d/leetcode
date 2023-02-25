#include <lt_help/lt.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size(), left = 0, right = 1;
        bool moveRight = true;
        while( left < right && right < size )
        {   int v = numbers[left] + numbers[right];
            if( v == target )
                return {left+1, right+1};
            
            if( v < target )
            {   if( moveRight )
                {   if( ++right == size )
                    {   --right;
                        moveRight = false;
                    }
                }
                else
                    ++left;
            }
            else /* if( v > target ) */
            {   if( moveRight )
                    moveRight = false;
                --right;
            }
        }
        return {};
    }
};



void test(vector<int> numbers, int target)
{
    cout << "input: target=" << target << ", numbers=";
    outputVector(numbers); 
    auto r = Solution().twoSum(numbers, target);
    cout << "; output: "; 
    outputVector(r);
    cout << ";" << endl;
}


int main(void)
{
    test({2,7,11,15}, 9);
}

// Result 
//
// 2022-11-19: Runtime 41ms 5.17% Memory 15.4MB 95.18%, https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/846364122/
// 2023-02-19: Runtime 12ms 78.38% Memory 15.7MB 7.40%, https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/900661027/



