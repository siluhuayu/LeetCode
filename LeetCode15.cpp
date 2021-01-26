#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums){
	int n = nums.size();
	vector<vector<int>> res;
	sort(nums.begin(),nums.end());//排序
	for(int i = 0; i < n; i++){//先固定一个元素
		if(i > 0 && nums[i] == nums[i-1])
			continue;
		int left = i + 1, right = n - 1;
		while(left < right){
			if(nums[i] + nums[left] + nums[right] == 0){
				vector<int> ans;
				ans.push_back(nums[i]);
				ans.push_back(nums[left]);
				ans.push_back(nums[right]);
				res.push_back(ans);
				while(nums[left + 1] == nums[left] && left <= n - 4)
					left++;
				left++;
				while(nums[right - 1] == nums[right] && right >= 4)
					right--;
				right--;
			}
			else if(nums[i] + nums[left] + nums[right] > 0)
			{
				while(nums[right - 1] == nums[right] && right >= 4)
					right--;
				right--;
			}
			else{
				while(nums[left + 1] == nums[left] && left <= n - 4)
					left++;
				left++;
			}
		}
	}
	return res;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	vector<vector<int>> res = threeSum(nums);
	int len = res.size();
	for(int i = 0; i < len; i++){
		for(int j = 0; j < 3; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}