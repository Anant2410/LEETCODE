/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count (ListNode* head)
    {
        int c=0;
        while(head)
        {
            head = head->next;
            c++;
        }
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1 = count(headA);
        int c2 = count(headB);
        
        int diff = c1-c2;
        if(diff<0)
        {
            diff = -1* diff;
            while(diff!=0)
            {
                headB = headB->next;
                diff--;
            }
        }
        else
        {
            while(diff!=0)
            {
                headA = headA->next;
                diff--;
            }
        }
        while(headA)
        {
            if(headA==headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};