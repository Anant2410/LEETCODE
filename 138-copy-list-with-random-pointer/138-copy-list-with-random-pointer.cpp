/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* item = head;
        Node* front= head;
        while(item)
        {
            front = item->next;
            Node* copy = new Node(item->val);
            item->next = copy;
            copy->next = front;
            item = front;
        }
        item = head;
        while(item)
        {
            if(item->random!=NULL)
            {
                item->next->random = item->random->next;
            }
            item = item->next->next;
        }
        item = head;
        Node* head1 = new Node(0);
        Node* copy = head1;
        while(item)
        {
            front = item->next->next;
            copy->next = item->next;
            item->next = front;
            copy = copy->next;
            item = item->next;
        }
        return head1->next;
    }
};