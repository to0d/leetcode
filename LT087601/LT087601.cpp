#include <lt_help/lt.h>



class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while( p2->next != NULL )
        {   p2 = p2->next;
            if( p2->next != NULL )
                p2 = p2->next;
            p1 = p1->next;
        }
        return p1;
    }
};

void test(ListNode* head)
{
    cout << "input: ";
    outputList(head);
    ListNode* r = Solution().middleNode(head);
    cout << "; output: " << r->val << ";" << endl;
}

int main(void)
{   
    test(makeList(5,1,2,3,4,5));
}


// Result 
//
// 2022-12-03: Runtime 0ms 100% Memory 7.1MB 78.86%, https://leetcode.com/problems/middle-of-the-linked-list/submissions/853688266/



