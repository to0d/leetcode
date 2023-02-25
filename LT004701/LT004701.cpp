#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        vector<vector<int>> res;
        if( nums.empty() )
            return res;

        target = nums.size();
        entry = vector<int>(target, 0); 
        used.clear(); 
        numbers.clear();       

        std::sort(nums.begin(), nums.end(), std::less<int>());
        
        int m(nums[0]), count(0);        
        for( int n : nums )
        {   if( m != n )
            {   numbers.push_back( m );
                used.push_back(count);
                count = 0;
            }
            
            m = n;
            ++count;
        }
        
        numbers.push_back( m );
        used.push_back( count);
        dfs(res, 0 );

        return res;
    }
    
    void dfs(vector<vector<int>>& res, int i ){  
        if( i == target )
        {   res.push_back(entry);
            return;
        }

        for( int j = 0; j < numbers.size(); ++j )
        {   if( used[j] > 0 )
            {   --used[j];
                entry[i] = numbers[j];
                dfs(res, i + 1);
                ++used[j];
            }
        }
    }
    
    vector<int> used;
    vector<int> entry;
    vector<int> numbers;
    int target;
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums); 
    vector<vector<int>> r = Solution().permuteUnique(nums);
    cout << "; output: "; 
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({1,1,2});
}

// Result 
//
// 2022-11-16: Runtime 4ms 91.89% Memory 8.5MB 81.32%, https://leetcode.com/problems/permutations-ii/submissions/844585320/
// 2023-02-17: Runtime 5ms 85.37% Memory 8.6MB 76.19%, https://leetcode.com/problems/permutations-ii/submissions/899809008/


