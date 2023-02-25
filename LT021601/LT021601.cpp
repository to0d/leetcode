#include <lt_help/lt.h>



class Solution {

    int number[ 10 ];

public:

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> r;
        if( k < 1 || k > 9 || n > (n*k - k*(k-1)/2) || n < (k*(k+1)/2) )
             return r;

        findCombSum(r, 0, k, n, 0);     
        return r;
    }

    void findCombSum(vector<vector<int> >& result, int index, int k, int n, int last)
    {
        if( index < k )
        {
            if( n <= 0 )
              return;
            for( int i = last + 1; i <= 9 && i <= n ; ++i)
            {   number[index] = i;
                findCombSum(result, index + 1, k, n - i, i);     
            }
            return;
        }

        // index == k
        if( n != 0 )
            return;

        result.push_back( vector <int> (number, number+index ));
    }
};

void test(int k, int n)
{
    cout << "input: k=" << k << ", n=" << n << "; output: ";
    vector<vector<int>> r = Solution().combinationSum3(k, n);
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{
    test(3, 9);
}

// Result 
//
// 2022-11-16: Runtime 0ms 100% Memory 6.3MB 85.41%, https://leetcode.com/problems/combination-sum-iii/submissions/844566775/
