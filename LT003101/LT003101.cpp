#include <lt_help/lt.h>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // build unique numbers and index map
        vector<int> numbers = nums;
        unordered_map<int,int> index_map;
        {   std::sort(numbers.begin(), numbers.end(), std::less<int>());
            numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());
            int i = 0;
            for( auto n : numbers)
                index_map[ n ] = i++;
        }

        vector<int> used(numbers.size(), 0);
        int max_index = numbers.size() - 1, max_pos = nums.size() - 1;
        int pos = max_pos;
        bool find = false;
        while (!find && pos >= 0)
        {   int i = index_map[nums[pos]];  
            ++used[i];   
            for(; !find && i < max_index; ++i)
            {   if( used[i+1] > 0 )
                {   --used[i+1];
                    nums[pos] = numbers[i+1];
                    find = true;
                }        
            }
            if(!find) 
                --pos;
        }

        for(++pos; pos <= max_pos; ++pos)
        {   int i = 0;
            while( i <= max_index && used[i] == 0 )
                ++i;
            --used[i];
            nums[pos] = numbers[i];
        }  
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    Solution().nextPermutation(nums);
    cout << "; output: ";
    outputVector(nums);
    cout << endl;
}

int main(void)
{  
    test({1, 2, 3});
}

// Result 
//
// 2022-11-15: Runtime 18ms 9.2% Memory 12.6MB 40.49%, https://leetcode.com/problems/next-permutation/submissions/843948828/
// 2023-02-17: Runtime 6ms 47.13% Memory 12.6MB 40.81%, https://leetcode.com/problems/next-permutation/submissions/899498101/


