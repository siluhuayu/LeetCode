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
void deleteNode(ListNode* node){
	node->val = node->next->val;
	node->next = node->next->next;
}
int main(){
	int n;
	cin >> n;
	int val;
	cin >> val;
	ListNode* head = create(n);
	ListNode* node = head;
	while(node){
		if(node->val == val)
			break;
		else
			node = node->next;
	}
	deleteNode(node);
	while(head){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	system("pause");
	return 0;
}