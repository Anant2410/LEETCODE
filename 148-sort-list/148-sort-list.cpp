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
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return NULL;
        vector<int> ans;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        sort(ans.begin(), ans.end());
        temp = head;
        temp->val = ans[0];
        temp = temp->next;
        for(int i=1;i<ans.size();i++)
        {
            temp->val = ans[i];
            temp = temp->next;
        }
        return head;
    }
};