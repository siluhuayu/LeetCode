#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int singleNumber(vector<int>& nums){
	int i = 0,len = nums.size();
	sort(nums.begin(),nums.end());
	for(; i < len; ){
		if(i == len - 1)
			break;
		if(nums[i] == nums[i+1])
			i += 2;
		else
			break;
	}
	return nums[i];
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int res = singleNumber(nums);
	cout << res << endl;
	system("pause");
	return 0;
}