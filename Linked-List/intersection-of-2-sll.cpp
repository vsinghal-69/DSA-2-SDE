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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
    ListNode *temp=head1;
    int n=0, m=0;
    while(temp)
    {
        temp=temp->next;
        ++n;
    }
    temp=head2;
    while(temp)
    {
        temp=temp->next;
        ++m;
    }
    temp=(n>=m)?head1:head2;
    ListNode *small=(n<m)?head1:head2;
    int extra=abs(n-m);
    while(extra--)
    {
        temp=temp->next;
    }
    while(temp)
    {
        if(temp==small)
            return temp;
        temp=temp->next;
        small=small->next;
    }
    return NULL;
    }
};