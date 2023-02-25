#include <lt_help/lt.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node *head) {
 
    struct Node* pCur;
    struct Node* pNext;
    struct Node* pNew;
    struct Node* pNewHead ;
    struct Node NewHead;
    
    // NULL List
    if( head == NULL )
    {   return NULL;                
    }
    
    // insert a next node for each node in previous list
    pCur = head;
    
    while( pCur != NULL )
    {
        pNext = pCur->next;
        pNew = (struct Node*) malloc(sizeof(struct Node));
        pNew->val    = pCur->val;
        pNew->next   = pNext;
        pNew->random = NULL;
        
        pCur->next = pNew;
        pCur = pNext;
    }
    
    // set random pointer for each new node
    pCur = head;
    while( pCur != NULL )
    {
        pNew  = pCur->next;
        pNext = pNew->next;
        
        if( pCur->random != NULL )
        {   pNew->random = pCur->random->next;
        }               
        
        pCur = pNext;
    }

    // detach every new node to a list
    pNewHead = &NewHead;
    pCur = head;
    while( pCur != NULL )
    {
        pNew  = pCur->next;
        pNext = pNew->next;
        
        pNewHead->next = pNew;
        pNewHead = pNew;
        
        pCur->next = pNext;
        pCur = pNext;
    }
    
    pNewHead->next = NULL;
    
    return NewHead.next;
}


int main(void)
{
    printf("output: done\n");
}

// Result 
//
// 2022-11-06: Runtime 15ms 16.54% Memory 8.2MB 100%, https://leetcode.com/problems/copy-list-with-random-pointer/submissions/855115503/




