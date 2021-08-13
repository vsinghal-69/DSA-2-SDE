Question:   Detect cycle in ll and remove it.

_______________________________________________________________________________________________

//method 1:  using hashing to detect cycle and break the cycle;

bool floydCycleRemoval(Node *head)
{
    if(!head || !head->next)
            return false;
        unordered_set<Node *>sn;
        Node *prev=NULL;
        while(head)
        {
            if(sn.count(head))
            {
                prev->next=NULL;
                return true;
            }
            sn.insert(head);
            prev=head;
            head=head->next;
        }
        return false;
}

_________________________________________________________________________________________________

//method 2: flyod's algorithm or hare and tortoise algorithm

//if fast and slow pointer catches up at any point, then that ll must have a cycle. It is not mandatory that fast and slow pointer will only catch up at the point of beginning of cycle.They may catch up at any node present in the cycle.

-------------------------------------------------------------------------------------------------------
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer

-----------------------------------------------------------------------------------------------------



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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode *fast=head, *slow=head;
        bool is_cycle=false;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                is_cycle=true;
                break;
            }
        }
        if(!is_cycle)
            return NULL;
        fast=head;
        while(fast != slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};