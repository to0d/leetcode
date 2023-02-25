#include <lt_help/lt.h>

bool less_interval(const vector<int>& a, const vector<int>& b) {   
    int d = a[0] - b[0];
    if( d == 0 )
        d = a[1] - b[1];
    return d < 0;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> rst;
        int row = mat.size();
        if( row == 0 )
            return rst;
        
        vector<vector<int>> power;
        for(int i = 0; i < row; ++i)
        {   vector<int>& vec = mat[i];
            int n = 0;
            for(int v : vec)
                if( v == 1 )
                    ++n;
                else
                    break;
            power.push_back({n, i}); 
        }
        
        std::sort(power.begin(), power.end(), less_interval);
        for(int i = 0;i < k; ++i)
            rst.push_back(power[i][1]);
        
        return rst;
    }
};



void test(vector<vector<int>> mat, int k)
{
    cout << "input: k=" << k << ", mat=";
    outputVector(mat);
    vector<int> r = Solution().kWeakestRows(mat, k);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   test({{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}}, 2);
}


// Result 
//
// 2022-12-12: Runtime 24ms 11.34% Memory 10.7MB 23.21%, https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/submissions/858672972/
// 2023-02-24: Runtime 15ms 54.9% Memory 10.6MB 22.41%, https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/submissions/904208812/



