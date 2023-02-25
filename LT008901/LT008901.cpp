#include <lt_help/lt.h>

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i = 0; i < n; ++i)
        {   int add = ( 1 << i );
            for(int j = res.size() - 1; j >= 0; --j)
                res.push_back( add + res[j] );
        }

        return res;
    }
};
            


void test(int n)
{
    cout << "input: " << n;
    vector<int> r = Solution().grayCode(n);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test(2);
}

// Result 
//
// 2022-11-23: Runtime 17ms 25.2% Memory 11.8MB 78.28%, https://leetcode.com/problems/gray-code/submissions/848360872/
// 2023-02-18: Runtime 12ms 47.50% Memory 11.8MB 61.84%, https://leetcode.com/problems/gray-code/submissions/900102390/
