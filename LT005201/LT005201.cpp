#include <lt_help/lt.h>

class Solution {
public:
    int totalNQueens(int n) {
        if( n < 0 )
            return 0;
        if( n <= 1 )
            return n;
        vector<int> vec(n,0);
        return _findQueue(vec,0,n);
    }
     
private: 
     int _findQueue(vector<int>& vec, int x, int n){
        if( x == n ) 
            return 1;

        int count = 0 ; 
        for( int v = 0; v < n; ++v)
        {   bool confic = false;
            for(int x1 = 0; x1 < x && !confic; ++x1)
            {   int y1 = vec[x1];
                if( y1 == v)
                {   confic = true;
                    break;
                }

                if( abs(x-x1) == abs(v-y1))
                {   confic = true;
                    break;
                }
            }
 
            if(!confic)
            {   vec[x] = v;       
                count += _findQueue(vec,x+1,n);	
            }
        }

        return count;
    }
};



void test(int n)
{
    cout << "input: " << n;    
    int r = Solution().totalNQueens(n);
    cout << "; output: " << r << endl;
}

int main(void)
{
    test(4);
}

// Result 
//
// 2022-11-10: Runtime 0ms 100% Memory 6MB 82.51%, https://leetcode.com/problems/n-queens-ii/submissions/840601272/
// 2023-02-17: Runtime 2ms 87.89% Memory 5.9MB 93.85%, https://leetcode.com/problems/n-queens-ii/submissions/899816364/


