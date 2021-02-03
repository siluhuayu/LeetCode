#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* buildTree(vector<int> arr){
	if(arr.size() == 0)
		return NULL;
	TreeNode *root = new TreeNode(arr[0]);
	queue<TreeNode*> q;
	q.push(root);
	int i = 1;
	while(i < arr.size()) {
		TreeNode *node = q.front();
		q.pop();
		if(node != NULL) {
			TreeNode*l = (arr[i] != -1)? new TreeNode(arr[i]) : nullptr;
			TreeNode*r = ((i + 1) < arr.size() && arr[i + 1] != -1)? new TreeNode(arr[i + 1]) : nullptr;
			node->left = l;
			node->right = r;
			q.push(l);
			q.push(r);
			i += 2;
		}
	}
	return root;
}
bool compare(TreeNode* p,TreeNode* q){
	if(p == NULL && q == NULL)
		return true;
	if(!p || !q)//Ò»¿ÕÒ»·Ç¿Õ
		return false;
	return (p->val == q->val) && compare(p->left,q->right) && compare(p->right,q->left);
}

bool isSymmetric(TreeNode* root){
	return compare(root,root);
}
int main(){
	int v;
	vector<int> a;
	cout << "enter the values one by one(must be >= 0)(-1 represents null):" << endl;
	while(cin >> v) {
		a.push_back(v);
		if (cin.get() == '\n')
            break;
	}
	TreeNode* root = buildTree(a);
	bool flag = isSymmetric(root);
	cout << flag << endl;
	system("pause");
	return 0;
}