#include<iostream>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target){
	vector<int> ans;
	for(int i = 0; i < nums.size(); i++)
		for(int j = i + 1; j < nums.size(); j++)
			if(nums[i]+nums[j] == target){
				ans.push_back(i);
				ans.push_back(j);
			}
	return ans;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int target;
	cin >> target;
	vector<int> ans = twoSum(nums,target);
	cout << "[" ;
	int i = 0;
	for(i = 0; i < ans.size()-1; i++)
		cout << ans[i] << ",";
	cout << ans[i] << "]";
	system("pause");
	return 0;
}

