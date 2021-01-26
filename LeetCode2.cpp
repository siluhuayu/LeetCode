#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* p = new ListNode(NULL);
	ListNode*l,*tmp;
	l = p;
	int carry = 0,sum;
	while(l1 && l2){
		sum = l1->val + l2->val + carry;
		if(sum >= 10){
			tmp = new ListNode(sum%10);
			p->next = tmp;
			p = tmp;
			sum /= 10;
			carry = 1;
		}
		else{
			carry = 0;
			tmp = new ListNode(sum);
			p->next = tmp;
			p = tmp;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	while(l1){
		sum = l1->val + carry;
		if(sum >= 10){
			tmp = new ListNode(sum%10);
			p->next = tmp;
			p = tmp;
			sum /= 10;
			carry = 1;
		}
		else{
			carry = 0;
			tmp = new ListNode(sum);
			p->next = tmp;
			p = tmp;
		}
		l1 = l1->next;
	}
	while(l2){
		sum = l2->val + carry;
		if(sum >= 10){
			tmp = new ListNode(sum%10);
			p->next = tmp;
			p = tmp;
			sum /= 10;
			carry = 1;
		}
		else{
			carry = 0;
			tmp = new ListNode(sum);
			p->next = tmp;
			p = tmp;
		}
		l2 = l2->next;
	}
	if(carry){
		tmp = new ListNode(carry);
		p->next = tmp;
		p = tmp;
	}
	return l->next;
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
	ListNode* l1 = new ListNode(NULL),*l2 = new ListNode(NULL);
	int n1,n2;
	cin >> n1 >> n2;
	l1 = create(n1);
	l2 = create(n2);
	ListNode *l = new ListNode(NULL);
	l = addTwoNumbers(l1,l2);
	cout << "[" << l->val;
	while(l->next){
		cout << "," << l->next->val ;
		l = l->next;
	}
	cout << "]" << endl;
	system("pause");
	return 0;
}

