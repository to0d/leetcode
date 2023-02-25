#include <lt_help/lt.h>



class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> _set;
        for(int num : nums)
            _set.insert(num);
        int count = 0; 
        ListNode* last = NULL;
        for(ListNode* node = head; node != NULL; node = node->next)
        {   if( _set.count(node->val) == 0 )
            {   last = NULL;
            }
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


