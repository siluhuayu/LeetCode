#include<iostream>
#include<vector>
using namespace std;
double findMaxAverage(vector<int>& nums, int k){
	int i = 0,len = nums.size();
	int sum = 0,maxsum;
	for(i; i < k; ++i)
		sum += nums[i];
	maxsum = sum;
	for(; i < len;++i)
	{
		sum = sum - nums[i-k] + nums[i];
		if(sum > maxsum)
			maxsum = sum;
	}
	return maxsum*1.0/k;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int k;
	cin >> k;
	double res = findMaxAverage(nums,k);
	cout << res << endl;
	system("pause");
	return 0;
}