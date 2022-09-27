/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* previous=NULL;
        ListNode* aageka = NULL;
        while(head)
        {
            aageka = head->next;
            head->next = previous;
            previous = head;
            head = aageka;
        }
        return previous;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast=head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow!=NULL)
        {
            if(slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};