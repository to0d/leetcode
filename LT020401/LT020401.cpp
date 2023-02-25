#include <lt_help/lt.h>

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2 ) 
            return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        for( int i = 2; i*i < n ; ++i )
            if( isPrime[i] )
                for( int j = i*i; j < n ; j += i)
                    isPrime[j] = false;
        
        int count = 0;
        for( bool is : isPrime)
            if( is )
                ++count;

        return count;
    }
};


   
void test(int n)
{
    cout << "input: " << n;;
    int r = Solution().countPrimes(n);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(0);
    test(1);
    test(10);
}

// Result 
//
// 2022-11-21: Runtime 449ms 21.89% Memory 10.3MB 73.78%, https://leetcode.com/problems/count-primes/submissions/847510396/
// 2023-02-22: Runtime 331ms 30.39% Memory 10.2MB 73.29%, https://leetcode.com/problems/count-primes/submissions/902629628/




