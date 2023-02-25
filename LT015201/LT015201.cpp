#include <lt_help/lt.h>



class Solution {
#define DBG(x)
//#define DBG(x) x
public:
    int maxProduct(vector<int>& nums) {
        int _max = INT_MIN;
        vector<int> values;
        int size = 0;
        for(int val : nums)
        {   if( val == 0 )
            {   _max = std::max(_max, 0);
                if( size > 0 )
                {   _max = std::max(_max, _maxOf(values));
                    values.clear();
                    size = 0;
                }
                DBG(cout << "1: " << _max << endl;)
            }
            else 
            {   DBG(cout << "while: before: "; for( int val : values ) cout << " " << val;)
                if( val > 0 )
                {   while ( size > 0)
                    {   int last_val = values[size-1];
                        int prod = last_val*val;
                        if( prod < 0 )
                            break;
                        val = prod;
                        values.pop_back();
                        --size;
                    }
                }
                values.push_back(val);
                size++;
                DBG(cout << " after: "; for( int val : values ) cout << " " << val; cout << endl;)
            }
        }
        DBG(cout << " final: "; for( int val : values ) cout << " " << val; cout << endl;)
        if( size > 0 )
            _max = std::max(_max, _maxOf(values));
        DBG(cout << "3: " << _max << endl;)
        return _max;
    }
    
    int _maxOf(vector<int>& values) {
        DBG(cout << " _maxOf: "; for( int val : values ) cout << " " << val; cout << endl;)
        int size = values.size(), neg = 0, idx0, idx1;
        for(int i = 0; i < size; ++i)
        {   int val = values[i];
            if( val < 0 )
            {   if( neg == 0 )
                    idx0 = i;
                else if(neg == 1)
                    idx1 = i;
                ++neg;
            }
        }

        if( neg % 2 == 0 )
        {   int _max = 1;
            for(int val : values)
                _max *= val;
            return _max;
        }
        
        if( neg > 1 )
        {   vector<int> values2;
            std::copy(values.begin(), values.begin()+idx0, std::back_inserter(values2));
            int _val = 1;
            for(int i = idx0; i <= idx1; ++i)
                _val *= values[i];
            values2.push_back(_val);
            std::copy(values.begin()+idx1+1, values.end(), std::back_inserter(values2));
            int _max2 = maxProduct(values2);
            
            vector<int> values3;
            std::copy(values.begin(), values.begin()+idx0+1, std::back_inserter(values3));
            int _max3 = maxProduct(values3);
            
            vector<int> values4;
            std::copy(values.begin()+idx0+1, values.end(), std::back_inserter(values4));
            int _max4 = maxProduct(values4);
            
            return std::max(_max2, std::max(_max3, _max4));
        }

        int _max = values[0];
        for(int i = 1; i < size; ++i)
            _max = std::max(_max, values[i]);
        return _max;
    }
};



void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums);
    int r = Solution().maxProduct(nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test({2,3,-2,4});
}


// Result 
//
// 2023-01-03: Runtime 16ms 15.50% Memory 14.7MB 5.16%, https://leetcode.com/problems/maximum-product-subarray/submissions/870508258/





