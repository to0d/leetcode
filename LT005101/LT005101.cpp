#include <lt_help/lt.h>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> output;
        if( n >= 1 )
        {   vector<int> vec(n, 0);
            _findQueue(vec,0,n, output);
        } 

        return output;
    }
    
private: 
    void _findQueue(vector<int>& vec, int x, int n, vector<vector<string> >& output){
        if( x == n )
        {   vector<string> r;
            for( int i = 0; i < n; ++i)
            {   string rr(n,'.');
                rr[vec[i]] = 'Q';
                r.push_back(rr);
            }
            output.push_back(r);
            return;
        }

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
                _findQueue(vec,x+1,n, output);
            }
        }
    }
};


     
void test(int n)
{
    cout << "input: " << n;    
    vector<vector<string>> r = Solution().solveNQueens(n);
    cout << "; output: ";
    outputVector(r);
    cout << endl;
}

int main(void)
{
    test(4);
}

// Result 
//
// 2022-11-10: Runtime 8ms 59.68% Memory 7.9MB 35.45%, https://leetcode.com/problems/n-queens/submissions/840595843/
// 2023-02-17: Runtime 6ms 76.13% Memory 7.9MB 35.23%, https://leetcode.com/problems/n-queens/submissions/899815523/


