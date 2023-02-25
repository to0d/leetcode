#include <lt_help/lt.h>

int countPrimes(int n) {
    if( n < 3 ) return 0; 
 
    int* isNotPrime = malloc(n*sizeof(int)); // 0: is Prime number
    memset(isNotPrime, 0, n*sizeof(int));    // 1: not Prime number

    for(int i=2; i*i < n; ++i)
    {   if( isNotPrime[i] == 1 )
            continue;
        for(int j=i*i; j < n; j+=i)
            isNotPrime[j] = 1;
    }

    int count = 0;
    for(int i=2; i < n; ++i)
        if(isNotPrime[i]==0)
            ++count;
    
    return count;
}



void test(int n)
{
    printf("input: %d", n);
    int r = countPrimes(n);
    printf("; output: %d;\n", r);
}

int main(void)
{
    test(0);
    test(1);
    test(10);
}

// Result 
//
// 2022-11-21: Runtime 303ms 35.8% Memory 116.6MB 16.23%, https://leetcode.com/problems/count-primes/submissions/847511718/
// 2023-02-22: Runtime 267ms 54.33% Memory 116.6MB 21.15%, https://leetcode.com/problems/count-primes/submissions/902630386/


