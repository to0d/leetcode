#include <lt_help/lt.h>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        list<int> max_list;
        vector<int> rst;
        for(int i = 0;i < len; ++i){
            int num = nums[i];
            while(!max_list.empty() && max_list.back() < num)
                max_list.pop_back();
            max_list.push_back(num);            
            if( i >= (k-1) ){
                rst.push_back(max_list.front());
                if( nums[i-k+1] == max_list.front())
                    max_list.pop_front();
            }
        }
        return rst;
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
// 2023-09-27: Runtime 352ms 6.94% Memory 189.9MB 5.3%, https://leetcode.cn/problems/sliding-window-maximum/submissions/469966901/



