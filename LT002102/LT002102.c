#include <lt_help/lt.h>

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode Temp;
    struct ListNode* l3 = &Temp;
    while( l1 != NULL && l2 != NULL )
    {
        if( l1->val > l2->val )
        {   l3->next = l2;
            l2 = l2->next;
        }
        else
        {   l3->next = l1;
            l1 = l1->next;
        }

        l3 = l3->next;
    }
    
    l3->next= (l1==NULL)? l2 : l1;
    return Temp.next;
}



void test(struct ListNode* l1, struct ListNode* l2)
{
    printf("input: l1=");
    outputList(l1);
    printf(", l2=");
    outputList(l2);
    struct ListNode* r = mergeTwoLists(l1, l2);
    printf("; output: ");
    outputList(r);
}

int main(void)
{
    test(makeList(3,1,2,4), makeList(3,1,3,4));
}

// Result 
//
// 2023-02-10: Runtime 5ms 42.3% Memory 6.1MB 74.31%, https://leetcode.com/problems/merge-two-sorted-lists/submissions/895350279/
// 2023-02-15: Runtime 3ms 82.29% Memory 6.2MB 57.62%, https://leetcode.com/problems/merge-two-sorted-lists/submissions/898564291/

