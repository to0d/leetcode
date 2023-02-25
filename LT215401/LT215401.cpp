#include <lt_help/lt.h>



class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        static int index[32];
        memset(index, 0, sizeof(index));
        for( auto num : nums)
        {   if( num % original != 0 )
                continue;
            int idx = _indexOf(num/original);
            // cout << "num=" << num << ", idx=" << idx << endl;
            if( idx != -1 )
                index[idx-1]++;
        }
        // for( auto v : index ) cout << v << " "; cout << endl;
        for(int i = 0; i < 32; ++i)   
            if( index[i] == 0 )
                return _numOf(i+1)*original;
        return original;
    }
    
    int _indexOf(int n)
    {   //1=>1, 10=>2, 100=>3, 10000=>4 
        if( n == 1 ) return 1;
        int num = 2;
        while( n > 1 )
        {   if( n == 2 )   
                break;
            if( (n & 1) != 0 )
                return -1;
            n = n >> 1;
            ++num;
        }
        return num;
    }
    
    int _numOf(int n)
    {   // 1=>1, 2==>10, 3==>100
        int val = 1;
        while( --n > 0 )
            val = val << 1;
        return val;
    }
};


void test(vector<int>& nums, int original)
{
    cout << "input: original=" << original << ", nums=";
    outputVector(nums);
    int r = Solution().findFinalValue(nums, original);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    vector<int> nums = {5,3,6,1,12};
    test(nums, 3);
}


// Result 
//
// 2022-12-02: Runtime 9ms 66.8% Memory 10.5MB 90.68%, https://leetcode.com/problems/keep-multiplying-found-values-by-two/submissions/853422660/



