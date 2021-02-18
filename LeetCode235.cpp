#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode
{
     int val;
     TreeNode* left;
	 TreeNode* right;
     TreeNode(int x):val(x), left(NULL), right(NULL){}
};
TreeNode* buildTree(vector<int> arr) {
	if(arr.size() == 0)
		return NULL;
	TreeNode* root = new TreeNode(arr[0]);
	queue<TreeNode*> q;
	q.push(root);
	int i = 1;
	while(i < arr.size()) {
		TreeNode *node = q.front();
		q.pop();
		if(node != NULL) {
			TreeNode *l = (arr[i] != -1)? new TreeNode(arr[i]) : nullptr;
			TreeNode *r = ((i + 1) < arr.size() && arr[i + 1] != -1)? new TreeNode(arr[i + 1]) : nullptr;
			node->left = l;
			node->right = r;
			q.push(l);
			q.push(r);
			i += 2;
		}
	}
	return root;
}
TreeNode* search(TreeNode* root, int a)
{
    if(root == NULL) 
		return NULL;
    if(root->val == a) 
		return root;
    TreeNode *p = search(root->left,a);
    if(p != NULL) 
		return p;
    return search(root->right,a);
}
TreeNode* lowestCommonAncestor(TreeNode*root, TreeNode* p, TreeNode* q)
{
    if(root == NULL) 
		return NULL;
	if(root->val == p->val || root->val == q->val)  
		return root;
    int xl = 0,xr = 0,yl = 0,yr = 0;
	if(search(root->left,p->val)){
		xl = 1;
		xr = 0;
	}
	else if(search(root->right,p->val)){
		xr = 1;
		xl = 0;
	}
	if(search(root->left,q->val)){
		yl = 1;
		yr = 0;
	}
	else if(search(root->right,q->val)){
		yr = 1;
		yl = 0;
	}
    if((xl || yl) && (xr || yr)) 
		return root;
    else if(xl && yl) 
		return lowestCommonAncestor(root->left, p, q);
    else if(xr && yr) 
		return lowestCommonAncestor(root->right, p, q);
    return NULL;
}
int main(){
	int v;
	vector<int> a;
	cout << "enter the values one by one(must be >= 0):" << endl;
	while(cin >> v) {
		a.push_back(v);
		if (cin.get() == '\n')
            break;
	}
    TreeNode* root = buildTree(a);
	int x, y;
	cout << "enter the two numbers:" << endl;
	cin >> x >> y;
	TreeNode* p = search(root,x),*q = search(root,y);
	TreeNode* res = lowestCommonAncestor(root,p,q);
	if(res)
		cout <<  res->val << endl;
	else
		cout << "no same parent" << endl;
	system("pause");
	return 0;
}