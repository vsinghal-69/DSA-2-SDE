Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.

Input Format
First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'. The next line contains a single integer k.

Constraints
n < 10^5

Output Format
Output a single line containing the node value at the kth element from last.

Sample Input
1 2 3 4 5 6 -1
3
Sample Output
4
Explanation
The linked list is 1 2 3 4 5 6. -1 is not included in the list. So the third element from the last is 4

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node * next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
}*head=NULL;

//using fast and slow pointers such that there is always a jump of k maintained b/w slow and fast pointers...
int solve(node * head, int k)
{
	node *fast=head, *slow=head;
	while(fast && k--)
	{
		fast = fast->next;
	}
	while(fast)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return slow->data;
}

int main()
{
	int x;
	cin>>x;
	if(x!=-1)
	{
		head=new node(x);
	}
	node * tail=head;
	cin>>x;
	while(x!=-1)
	{
		tail->next=new node(x);
		tail  = tail->next;
		cin>>x;
	}
	int k;
	cin>>k;
	cout<<solve(head, k);
	return 0;
}