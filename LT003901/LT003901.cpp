#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {        
        vector<int> path;
        vector<vector<int>> result;
        find(candidates, 0, target, path, result);
        return result;
    }
    
    void find(vector<int>& candidates, int index, int target, vector<int>& path, vector<vector<int>>& result){        
        if( target == 0 )
        {   result.push_back(path); 
            return;
        }

        int size = candidates.size();
        if( index == size || target < 0)
            return;

        int value = candidates[index];
        if( target >= value )
        {   path.push_back(value);
            find(candidates, index, target-value, path, result);
            path.pop_back();
        }

        find(candidates, index+1, target, path, result);
    }
};



void test(vector<int> candidates, int target)
{
    cout << "input: target=" << target << ", candidates=";
    outputVector(candidates);
    auto r = Solution().combinationSum(candidates, target);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test({2,3,6,7}, 7);
}

// Result 
//
// 2023-02-10: Runtime 4ms 82.22% Memory 17MB 32.26%, https://leetcode.com/problems/combination-sum/submissions/895376470/
// 2023-02-17: Runtime 8ms 60.70% Memory 16.7MB 33.5%, https://leetcode.com/problems/combination-sum/submissions/899524836/


