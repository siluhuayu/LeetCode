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
int maxDepth(TreeNode* root){
	if(root == NULL)
		return 0;
	int lheight = maxDepth(root->left) + 1;
	int rheight = maxDepth(root->right) + 1;
	return lheight > rheight ? lheight:rheight;
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
	int depth = maxDepth(root);
	cout << depth << endl;
	system("pause");
	return 0;
}