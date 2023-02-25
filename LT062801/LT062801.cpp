#include <lt_help/lt.h>

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //  negative ------- 0 --------- positive
        //  x1 x2     n3 n2 n1            m1 m2 m3
        // 
        // max product 
        // 1: positive_num>= 3 or negative_num >= 2
        //      a) negative_num < 2: m1*m2*m3  m1>m2>m3>0, max 3 positive numbers
        //      b) negative_num >=2: m1*m2*m3 or x1*x2*m1
        // 2: positive_num = 2: m1*m2*n1  m1>m2>0, 2 positive numbers; n1<0, max negative number
        // 3: positive_num = 1: m1*x1*x2  m1>0, positive number; x1<x2<0, min negative 2 numbers
        // 4: positive_num = 0: n1*n2*n3  n3<n2<n1<0, min 3 negative numbers
        vector<int> m(3, 0);
        vector<int> n(5, 0);
        int positive_num=0, negative_num=0;        
        for(int v : nums)        
        {   if( v > 0 )
            {   if( positive_num < 3 )
                    m[positive_num++] = v;
                else if(v > m[0] )
                    m[0] = v;
                if(positive_num == 3)
                    std::sort(m.begin(), m.end());
            }
            else
            {   if( negative_num < 5 )
                    n[negative_num++] = v;
                else if(v < n[1])
                    n[1] = v;
                else if(v > n[2])
                    n[2] = v;
                if(negative_num == 5)
                    std::sort(n.begin(), n.end());
            }
        }
        
        if( positive_num < 3 )
            std::sort(m.begin(), m.begin()+positive_num);
        
        if( negative_num < 5 )
            std::sort(n.begin(), n.begin()+negative_num);

        if( (positive_num + negative_num) < 3 ) // too many zero
            return 0;

        int a = -1, b = -1;
       
        if( positive_num >= 3 )
            a = m[0]*m[1]*m[2];
        
        if( positive_num > 0 && negative_num >= 2)
            b = m[positive_num-1]*n[0]*n[1];
        
        if( a > 0 || b > 0)
            return std::max(a, b);

        if( positive_num == 2)
            return m[0]*m[1]*n[negative_num-1];

        if( positive_num == 1)
            return m[0]*n[0]*n[1];
        
        if( positive_num == 0)
            return n[negative_num-3]*n[negative_num-2]*n[negative_num-1];
        
        return 0;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().maximumProduct(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test({1,2,3,4}); 
    test({1,2,3,-2,-5}); 
}


// Result 
//
// 2022-11-30: Runtime 124ms 5.10% Memory 27.7MB 44.72%, https://leetcode.com/problems/maximum-product-of-three-numbers/submissions/851858785/
// 2023-02-24: Runtime 57ms 40.68% Memory 27.7MB 86.55%, https://leetcode.com/problems/maximum-product-of-three-numbers/submissions/904181424/



