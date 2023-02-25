#include <lt_help/lt.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode tmp, *node = &tmp;
    int val = 0;

    while( l1 != NULL || l2 != NULL || val !=0 )
    {
        if( l1 != NULL ) 
        {   val += l1->val;
            l1  =l1->next;
        }
        
        if( l2 != NULL ) 
        {   val += l2->val;
            l2  =l2->next;
        }

        node->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        node->next->val = val%10;
        node = node->next;
        val /= 10;
    }

    node->next = NULL;
    return tmp.next;
}


void test(struct ListNode* l1, struct ListNode* l2)
{
    printf("input: l1="); 
    outputList(l1); 
    printf(", l2="); 
    outputList(l2);
    struct ListNode* l3 = addTwoNumbers(l1, l2);
    printf("; output: "); 
    outputList(l3);
    printf(";\n");
}

int main(void)
{
    test(makeList(3, 2, 4, 3), makeList(3, 5, 6, 4));
}

// Result 
//
// 2023-02-06: Runtime 19ms 40.97% Memory 7.6MB 67.38%, https://leetcode.com/problems/add-two-numbers/submissions/892677232/
// 2023-02-15: Runtime 15ms 66.27% Memory 7.8MB 33.21%, https://leetcode.com/problems/add-two-numbers/submissions/898519394/


