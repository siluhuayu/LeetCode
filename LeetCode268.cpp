#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int missingNumber(vector<int>& nums){
	int len = nums.size();
	sort(nums.begin(),nums.end());
	int n = nums[len-1];
	int k = 0;
	for(int i = 0; i < len; ++i){
		if(nums[i] > k){
			return k;
		}
		else if(nums[i] == k){
			if(i < len - 1 && nums[i+1] != k)
				k++;
		}
	}
	k++;
	return k;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int res = missingNumber(nums);
	cout << res << endl;
	system("pause");
	return 0;
}