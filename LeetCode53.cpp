#include<iostream>
#include<vector>
using namespace std;
int maxSubArray(vector<int>& nums){
	int len = nums.size();
	int sum = nums[0],maxsum = nums[0];
	for(int i = 0; i < len; i++){
		sum = max(sum+nums[i],nums[i]);
		maxsum = max(maxsum,sum);
	}
	return maxsum;
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
	int maxsum = maxSubArray(nums);
	cout << maxsum << endl;
	system("pause");
	return 0;
}