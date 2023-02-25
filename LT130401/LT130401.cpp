#include <lt_help/lt.h>



class Solution {
public:
    vector<int> sumZero(int n) {
        int m = n/2;
        vector<int> rst;
        for(int i = 0; i < m; ++i)
        {   rst.push_back(i+1);
            rst.push_back(-i-1);
        }
        if( (n%2 == 1) )
            rst.push_back(0);
        return rst;
    }
};


void test(int n)
{
    cout << "input: " << n;
    vector<int> r = Solution().sumZero(n);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test(5);
}


// Result 
//
// 2022-12-12: Runtime 0ms 100% Memory 6.6MB 83.44%, https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/submissions/858507591/



