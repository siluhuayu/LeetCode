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
vector<vector<int>> levelOrder(TreeNode* root){
	vector<vector<int>> res;
	if(root == NULL)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		int sz = q.size();
		res.push_back(vector<int>());
		for(int i = 0; i < sz; ++i){
			TreeNode* temp = q.front();
			q.pop();
			res.back().push_back(temp->val);
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
	reverse(res.begin(),res.end());
	return res;
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
	vector<vector<int>> res = levelOrder(root);;
	for(int i = 0; i < res.size(); ++i){
		for(int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}