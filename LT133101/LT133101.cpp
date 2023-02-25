#include <lt_help/lt.h>

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int size = arr.size();
        if( size == 0 )
            return arr;
        
        vector<int> copy;
        std::copy(arr.begin(), arr.end(), std::back_inserter(copy));
        std::sort(copy.begin(), copy.end());
        
        unordered_map<int,int> _map;
        for(int i = 0, rank = 0, last = arr[0]-1; i < size; ++i )
        {   int val = copy[i];
            if( val != last)
            {   _map[val] = ++rank;
                last = copy[i];
            }
        }
        
        for(int i = 0; i < size; ++i )
            arr[i] = _map.find(arr[i])->second;
        
        return arr;
    }
};



void test(vector<int> arr)
{
    cout << "input: ";
    outputVector(arr);
    vector<int> r = Solution().arrayRankTransform(arr);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({40,10,20,30});
}


// Result 
//
// 2022-12-12: Runtime 229ms 10.58% Memory 40.5MB 49.87%, https://leetcode.com/problems/rank-transform-of-an-array/submissions/858498611/
// 2023-02-24: Runtime 103ms 83.10% Memory 40.5MB 49.94%, https://leetcode.com/problems/rank-transform-of-an-array/submissions/904207893/




