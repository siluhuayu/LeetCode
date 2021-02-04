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
TreeNode* dfs(vector<int>& nums,int left,int right){
	if(left > right)
		return NULL;
	int mid = (left + right) / 2;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = dfs(nums,left,mid-1);
	root->right = dfs(nums,mid+1,right);
	return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums){
	return dfs(nums,0,nums.size()-1);
}
void show(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root); 
	while(!q.empty()){
		TreeNode* cur = q.front();
		q.pop();  
		if(cur == NULL)
		{
			cout << "null" << " ";
			continue;
		}
		cout << cur->val << " ";			
		if(cur->left || cur->right){
			q.push(cur->left);  
			q.push(cur->right);
		}
	} 
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v)
	{
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	TreeNode* root = sortedArrayToBST(nums);
	show(root);
	cout << endl;
	system("pause");
	return 0;
}
