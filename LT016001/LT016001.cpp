#include <lt_help/lt.h>

//           |<-- a -->|
//   A:          a1 -> a2
//                      \ |<-- c -->|
//                        c1 -> c2 -> c3
//                      /            
//   B:     b1 -> b2 ->? b3
//          |<-- b -->|
//          
//          
//   la = length(A) = a + c;
//   lb = length(B) = b + c;
//   
//   Reverse list b
//   
//           |<-- a -->|
//   A:          a1 -> a2
//                      \ |<-- c -->|
//                        c1 -> c2 -> c3
//                      /             \
//   B:     b1 -> b2 -> b3             Tail
//          |<-- b -->| 
//
//   Now, iterate list A' 
//
//   lc = length(A') = a + b;
//   
//   So, you can get the value of "c":
//       
//      c = (la+lb-lc)/2;
//   
//   The intersect node should be at position c from tail. 

ListNode* travelList(ListNode *head, int& len) {
    len = 0;
    ListNode *tail = head;
    if( tail == NULL )
        return NULL;
    for(++len; tail->next != NULL; tail = tail->next)
        ++len;
    return tail;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if( headA == NULL || headB == NULL ) 
            return NULL;
        if( headA == headB ) 
            return headA;

        int alen = 0, blen = 0, clen = 0;        
        ListNode *TailA = travelList(headA, alen);
        ListNode *TailB = travelList(headB, blen);
        if( TailA != TailB )
           return NULL;

        ListNode *longHead  = alen>blen? headA : headB;
        ListNode *shortHead = alen>blen? headB : headA;

        reverseList(longHead);
        travelList(shortHead, clen);

        ListNode *target = TailA;
        for( int d = (alen + blen - clen) / 2; d > 0; --d )
            target = target->next;
        
        reverseList(TailA);     
        return target;
    }

    ListNode* reverseList(ListNode* head) { // refer LT020601.cpp
        ListNode* last = NULL;
        while( head != NULL )
        {   ListNode* next = head->next;
            head->next = last;
            last = head;
            head = next;
        }

        return last;
    }
};



void test(ListNode *l1, ListNode *l2, ListNode *l3) {
    int len; 
    travelList(l1, len)->next = l3;
    travelList(l2, len)->next = l3;
    
    cout << "input: headA=";
    outputList(l1);
    cout << ", headB=";
    outputList(l2);
    ListNode* r = Solution().getIntersectionNode(l1, l2);
    cout << "; output: ";
    outputList(r);
    cout << ";" << endl;
}

int main(void)
{
     test(makeList(1,4), makeList(2,5,6), makeList(4, 1,8,4,5));
}

// Result 
//
// 2022-11-21: Runtime 41ms 76.34% Memory 14.1MB 12.30%, https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/847487044/
// 2023-03-05: Runtime 47ms 74.31% Memory 14.6MB 36%, https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/908996564/



