#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target){
	int left = 0,right = nums.size() - 1;
	if(right == -1)
		return 0;
	while(left < right){
		int mid = (left + right)/2;
		if(nums[mid] < target)
			left = mid + 1;
		else if(nums[mid] > target)
			right = mid - 1;
		else
			return mid;
	}
	return target <= nums[left] ? left : left + 1;
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
	int res = searchInsert(nums,target);
	cout << res << endl;
	system("pause");
	return 0;
}