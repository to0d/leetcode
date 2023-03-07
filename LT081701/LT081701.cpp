#include <lt_help/lt.h>

class Solution {
public:
#define MAX_NUM 10000
    int numComponents(ListNode* head, vector<int>& nums) {
        vector<bool> hit (MAX_NUM, false);
        for(int num : nums)
            hit[num] = true;
        int count = 0; 
        ListNode* last = NULL;
        for(ListNode* node = head; node != NULL; node = node->next)
        {   if( !hit[node->val] )
                last = NULL;
            else
            {   if( last == NULL )
                    ++count;
                last = node;
            }
        }
        return count;
    }
};



void test(ListNode* head, vector<int> nums)
{
    cout << "input: list="; 
    outputList(head); 
    cout << ", nums="; 
    outputVector(nums); 
    int r = Solution().numComponents(head, nums);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{
    test(makeList(5, 0,1,2,3,4), {0,3,1,4});
}

// Result 
//
// 2023-01-18: Runtime 35ms 90.50% Memory 21.6MB 53.38%, https://leetcode.com/problems/linked-list-components/submissions/880428959/
// 2023-03-07: Runtime 28ms 97.69% Memory 19.4MB 95.67%, https://leetcode.com/problems/linked-list-components/submissions/910925201/


