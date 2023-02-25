#include <lt_help/lt.h>

class Solution {
public:
    string getPermutation(int n, int k) {
        static const int factor[] = {1,1,2,6,24,120,720,720*7,720*7*8}; //n!

        if( n == 1 ) 
            return "1";

        string numbers = "123456789", res;
        k--;
        for(int i = n - 1;  i >= 0; --i)
        {   int m = factor[i] ;
            int ii = k/m;   
            k %=m;
            res.push_back(numbers.at(ii));
            numbers.erase(numbers.begin() + ii);            
        }

        return res;
    }
};
            


void test(int n, int k)
{
    cout << "input: n=" << n << ", k=" << k;
    string r = Solution().getPermutation(n, k);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(3, 3); 
}


// Result 
//
// 2022-11-23: Runtime 5ms 29.14% Memory 5.9MB 83.97%, https://leetcode.com/problems/permutation-sequence/submissions/848334577/
// 2023-02-17: Runtime 4ms 53.79% Memory 5.9MB 84.35%, https://leetcode.com/problems/permutation-sequence/submissions/899830530/

