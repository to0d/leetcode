#include <lt_help/lt.h>



// #define _DBG

class Solution {
public:

    int nthSuperUglyNumber(int n, vector<int>& primes) {
     
#ifdef _DBG
        cout << "nthSuperUglyNumber: " << n << endl;
#endif     
        vector<int> uglyNumbers;
        uglyNumbers.push_back(1);
        uglyNumbers.push_back(primes[0]);
        
        typedef vector<int>::iterator iter;
        
        int maxFactor = primes[primes.size() - 1];
        
        while( n > (int) uglyNumbers.size() )
        {
            int maxUgly = uglyNumbers[ uglyNumbers.size() - 1] + 1;
            int minNextUgly = INT_MAX;
            int factorCount = primes.size();
            int nextFactor = -1;
#ifdef _DBG
            cout << "      uglyNumbers.size(): " << uglyNumbers.size() << endl;
            cout << "                 maxUgly: " << maxUgly << endl;
#endif 
            if( maxUgly < maxFactor )
            {
                iter factorPos = lower_bound( primes.begin(), primes.end(), maxUgly);
                factorCount = factorPos - primes.begin();
                nextFactor = * factorPos;
            }
#ifdef _DBG
            cout << "      uglyNumbers.size(): " << uglyNumbers.size() << endl;
            cout << "             factorCount: " << factorCount << endl;
            cout << "              nextFactor: " << nextFactor << endl;
#endif 

            for(int i = 0; i < factorCount; ++i)
            {              
                int factor = primes[i];
                int lowUgly = uglyNumbers[ uglyNumbers.size() - 1] / factor + 1;
                iter lastUglyPos = lower_bound( uglyNumbers.begin(), uglyNumbers.end(), lowUgly);
                int lastUgly = *lastUglyPos;
                int ugly = lastUgly * factor;
                minNextUgly = min( ugly, minNextUgly);
                if( lastUgly == lowUgly && lastUglyPos == (uglyNumbers.begin() + 1) )
                    break;
                
#ifdef _DBG
            cout << "factor=" << factor << ",ugly=" << ugly <<",minNextUgly=" <<minNextUgly << endl;
#endif 
            }
            
            if( nextFactor != -1 )
                minNextUgly = min( nextFactor, minNextUgly);
            
            uglyNumbers.push_back(minNextUgly);
        }
        
        return uglyNumbers[ n-1 ];
    }
};

void test(int n, vector<int>& primes)
{
    cout << "input: n=" << n << ", primes=";
    outputVector(primes);
    cout << "; output: "; 
    int r = Solution().nthSuperUglyNumber(n, primes);
    cout << r << ";" << endl;
}

int main(void)
{
    vector<int> primes = {2,7,13,19};
    test(12, primes);
}


// Result 
//
// 2022/11/16
// 35
// [2,3,11,13,17,23,29,31,37,47]
// Wrong Answer