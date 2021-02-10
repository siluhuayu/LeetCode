#include<iostream>
using namespace std;
struct ListNode {
	int val;
    ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* create(int n)
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
	p->next = NULL; 
	return head;
}
ListNode* removeElements(ListNode* head, int val){
	if(head == NULL)
		return NULL;
	ListNode* h = head,*temp;
	while(h->next){
		if(h->next->val == val)
		{
			temp = h->next;
			h->next = temp->next;
			delete temp;
		}
		else
			h = h->next;
	}
	return head->val == val ? head->next:head;
	
}
int main(){
	int n;
	cin >> n;
	int val;
	cin >> val;
	ListNode* head = create(n);
	ListNode* nhead = removeElements(head,val);
	while(nhead){
		cout << nhead->val << " ";
		nhead = nhead->next;
	}
	cout << endl;
	system("pause");
	return 0;
}