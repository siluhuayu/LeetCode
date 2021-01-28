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
ListNode* swapPairs(ListNode* head){
	if(head == NULL || head->next == NULL)
		return head;
	ListNode* nhead = head->next;
	head->next = swapPairs(nhead->next);
	nhead->next = head;
	return nhead;
}
int main(){
	int n;
	cin >> n;
	ListNode* head = create(n);
	ListNode* nhead = swapPairs(head);
	while(nhead){
		cout << nhead->val << " ";
		nhead = nhead->next;
	}
	cout << endl;
	system("pause");
	return 0;
}
