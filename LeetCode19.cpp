#include<iostream>
using namespace std;
struct ListNode {
	int val;
    ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int length(ListNode* head){
	int length = 0;
	while(head){
		++length;
		head = head->next;
	}
	return length;
}
ListNode* removeNthFromEnd(ListNode* head, int n){
	if(head == NULL)
		return NULL;
	int len = length(head);
	ListNode* h = new ListNode(0,head);
	ListNode* p = h;
	for(int i = 0; i < len - n; i++)
		p = p->next;
	p->next = p->next->next;
	ListNode* temp = h->next;
	delete h;
	return temp;
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
	ListNode* head = new ListNode(NULL);
	int n;
	cin >> n;
	int num;
	cin >> num;
	head = create(num);
	ListNode *l = new ListNode(NULL);
	l = removeNthFromEnd(head,n);
	cout << "[" << l->val;
	while(l->next){
		cout << "," << l->next->val ;
		l = l->next;
	}
	cout << "]" << endl;
	system("pause");
	return 0;
}