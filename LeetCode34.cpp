#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target){
	vector<int> ans;
	int len = nums.size();
	int i;
	for(i = 0; i < len; i++){
		if(nums[i] == target){
			ans.push_back(i);
			break;
		}
	}
	if(i == len)
		ans.push_back(-1);
	for(i = len - 1; i >= 0; i--)
		if(nums[i] == target){
			ans.push_back(i);
			break;
		}
	if(i == -1)
		ans.push_back(-1);
	return ans;
}
int main(){
	int v;
	vector<int> nums;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int target;
	cin >> target;
	vector<int> ans = searchRange(nums,target);
	for(int i = 0; i < 2; i++)
		cout << ans[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}