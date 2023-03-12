#include <lt_help/lt.h>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        list<int> max_list; 
        int size = nums.size();
        for(int i = 0, j = 0; j < size; ++j)
        {   int num = nums[j];
            while( max_list.size() > 0 && max_list.back() < num )
                max_list.pop_back();
            max_list.push_back(num);
            if( (j - i + 1) == k )
            {   res.push_back(max_list.front());
                if( nums[i] == max_list.front() )
                    max_list.pop_front();
                ++i;
            }
        }
        return res;
    }
};



void test(vector<int> nums, int k)
{
    cout << "input: k=" << k << ", nums=";
    outputVector(nums);
    vector<int> r = Solution().maxSlidingWindow(nums, k);
    cout << "; output: ";
    outputVector(r);
    cout << ";" << endl;
}

int main(void)
{   
    test({1,3,-1,-3,5,3,6,7}, 3);
}


// Result 
//
// 2023-03-12: Runtime 456ms 26.6% Memory 194.2MB 13.74%, https://leetcode.com/problems/sliding-window-maximum/submissions/913748432/, https://leetcode.com/problems/sliding-window-maximum/solutions/3275508/c-easy-to-understand-sliding-window/



