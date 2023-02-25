#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> r(k, 0);     
        fill(res, r, 0, 1, n, k);
        return res;
    }
    
    void fill( vector<vector<int>>& res, vector<int>& r, int i, int m, int n, int k){
        if( i == k )
        {   res.push_back(r);
            return;
        }

        int mj = n+i+1-k;	//optimize a
        for( int j = m; j <= mj ; ++j)
        {   r[i] = j;
            fill(res, r, i+1, j+1, n, k );
        }
    }
};



void test(int n, int k)
{
    cout << "input: n=" << n << ", k=" << k; 
    vector<vector<int>> r = Solution().combine(n, k);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{ 
    test(4, 2);
}

// Result 
//
// 2022-11-19: Runtime 12ms 95% Memory 9MB 91.13%, https://leetcode.com/problems/combinations/submissions/846164194/
// 2023-02-18: Runtime 8ms 97.68% Memory 9.1MB 81.98%, https://leetcode.com/problems/combinations/submissions/900098835/


