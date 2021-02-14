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
//ListNode* reverseList(ListNode *head)
//{
//    ListNode *pcur,*pnext,*ppre;
//    ppre = head;
//	pcur = head->next;
//	pnext = pcur->next;
//    pcur->next = ppre;
//	ppre->next = NULL;//完成首次交换 
//    ppre = pcur;
//	pcur = pnext;  //指针后移 
//	pnext = (pcur)?pcur->next:NULL; //判断是否结束 
//    while(pcur != NULL)
//    {
//        pcur->next = ppre;
//        ppre = pcur;
//		pcur = pnext;
//        pnext = (pcur)?pcur->next:NULL;
//    }   //进行交换 
//    return ppre;
//}
ListNode* reverseList(ListNode *head){
	if(head == NULL || head->next == NULL)
		return head;
	ListNode* nhead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return nhead;
}
int main(){
	int n;
	cin >> n;
	ListNode* head = create(n);
	ListNode* nhead = reverseList(head);
	while(nhead){
		cout << nhead->val << " ";
		nhead = nhead->next;
	}
	cout << endl;
	system("pause");
	return 0;
}
