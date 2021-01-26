#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
	ListNode* h = new ListNode();
	ListNode* pre = h;
	while(l1 && l2){
		if(l1->val <= l2->val){
			pre->next = l1;
			l1 = l1->next;
		}
		else{
			pre->next = l2;
			l2 = l2->next;
		}
		pre = pre->next;
	}
	pre->next = l1 ? l1:l2;
	return h->next;
}
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
int main(){
	ListNode* l1,*l2;
	int n1,n2;
	cin >> n1 >> n2;
	l1 = create(n1);
	l2 = create(n2);
	ListNode *l = new ListNode(NULL);
	l = mergeTwoLists(l1,l2);
	cout << "[" << l->val;
	while(l->next){
		cout << "," << l->next->val ;
		l = l->next;
	}
	cout << "]" << endl;
	system("pause");
	return 0;
}