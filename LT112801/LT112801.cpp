#include <lt_help/lt.h>

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        static int buf[100];
        memset(buf, 0, sizeof(buf));
        int count = 0;
        for(vector<int>& v : dominoes)
        {   int x = std::max(v[0], v[1]), y = std::min(v[0], v[1]);
            if( buf[x*9+y]++ > 0 )
                count += (buf[x*9+y]-1);
        }
        return count;
    }
};



void test(vector<vector<int>> dominoes)
{
    cout << "input: ";
    outputVector(dominoes);
    int r = Solution().numEquivDominoPairs(dominoes);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   test({{1,2},{1,2},{1,1},{1,2},{2,2}});
}


// Result 
//
// 2022-12-11: Runtime 103ms 18.4% Memory 21.9MB 88.29%, https://leetcode.com/problems/number-of-equivalent-domino-pairs/submissions/857924030/
// 2023-02-24: Runtime 54ms 67.97% Memory 22MB 65.12%, https://leetcode.com/problems/number-of-equivalent-domino-pairs/submissions/904201818/



