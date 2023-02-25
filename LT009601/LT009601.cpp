#include <lt_help/lt.h>

//	f(n) = Sum ( f(n-i-1)*f(i) ),  i = 0,1,2.. n-1  ;  when n > 1
//	       1                                        ;  when n <= 1 */

class Solution {
public:
    Solution() : nHeap(1000, 0){	
        nHeap[0]  = 1;
        nHeap[1]  = 1; 
    }

    int numTrees(int n){
        int val = 0; 
        if( n < 0 || ( val = nHeap[n] ) != 0 ) 
            return val;

        for( int j = n - 1; j >= 0 ; --j )
            val += numTrees(j) * numTrees( n - j - 1);

        nHeap[n] = val;
        return val;
    }
    
private:
    vector<int> nHeap;
};



void test(int n)
{
    cout << "input: " << n;
    int r = Solution().numTrees(n);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test(3);
    test(1);
}

// Result 
//
// 2022-11-22: Runtime 6ms 14.79% Memory 6MB 80.14%, https://leetcode.com/problems/unique-binary-search-trees/submissions/848092023/
// 2023-02-22: Runtime 2ms 51.76% Memory 6.2MB 15.44%, https://leetcode.com/problems/unique-binary-search-trees/submissions/902636326/



