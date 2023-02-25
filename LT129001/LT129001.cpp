#include <lt_help/lt.h>



class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* node = head;
        int v = 0;
        for(; node != NULL ; node = node->next)
            v = v << 1 | node->val;
        return v;
    }
};


void test(ListNode* head)
{
    cout << "input: ";
    outputList(head);
    int r = Solution().getDecimalValue(head);
    cout << "; output: " << r << ";" << endl;
}

int main(void)
{   
    test(makeList(3,1,0,1));
}


// Result 
//
// 2022-12-12: Runtime 3ms 52.89% Memory 8.2MB 70.25%, https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/858691183/



