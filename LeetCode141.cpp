#include<iostream>
using namespace std;
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode *head){
	if(head == NULL || head->next == NULL)
		return false;
	ListNode* fast = head->next,*slow = head;
	while(slow != fast){
		if(fast == NULL || fast->next == NULL)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}
ListNode* create(int n,int pos)
{   
	ListNode*p, *q; 
	if (n == 0) 
		return NULL; 
	ListNode* head = new ListNode(NULL); 
	p = head;
	for (int i = 1; i < n; i++) { 
		cin >> p->val; 
		q = new ListNode (NULL); 
		p->next = q; 
		p = q; 
	} 
	cin >> p->val;
	if(pos == -1)
		return head;
	ListNode* temp = head;
	int count = 0;
	while(count < pos)
	{
		temp = temp->next;
		count++;
	}
	p->next = temp; 
	return head;
}
int main(){
	int n;
	cin >> n;
	int pos;
	cin >> pos;
	ListNode* head = create(n,pos);
	bool res = hasCycle(head);
	cout << res << endl;
	system("pause");
	return 0;
}