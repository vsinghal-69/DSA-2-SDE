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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            ++n;
        }
        if(n==1)
            return 1;
        int k=n/2;
        temp=head;
        ListNode* end1=head;
        while(temp!=NULL)
        {
            end1=temp;
            temp=temp->next;
            if(--k==0)
                break;
        }
        ListNode* curr=temp;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        ListNode* r=prev;
        ListNode* l=head;
        k=n/2;
        while(k)
        {
            if(l->val != r->val)
                return 0;
            l=l->next;
            r=r->next;
            --k;
        }
        return 1;
        
    }
};