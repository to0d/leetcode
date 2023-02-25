#include <lt_help/lt.h>



bool bigger(const string & n1, const string & n2) 
{
    if( n1.size() == n2.size() )
    {   return strcmp(n1.c_str(), n2.c_str()) > 0;                    
    }
    else
    {   string n12 = n1 + n2;
        string n21 = n2 + n1;
        return bigger(n12, n21);
    } 
}

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        
        string rst = "";
        vector<string> num_array;
      
        for( auto n : nums )
            num_array.push_back(to_string(n));
        
        std::sort(num_array.begin(), num_array.end(), bigger);

        for( auto n : num_array )
            rst += n; 
        
        if(rst.size() > 1 && rst[0] == '0')
            return "0";
        
        return rst;
    }
};
    


void test(vector<int> nums)
{
    cout << "input: ";
    outputVector(nums); 
    string r = Solution().largestNumber(nums);
    cout << "; output: " << r << ";" << endl;
}


int main(void)
{
    test({10,2});
}

// Result 
//
// 2022-11-19: Runtime 3ms 98.26% Memory 11.4MB 49.79%, https://leetcode.com/problems/largest-number/submissions/846355274/

