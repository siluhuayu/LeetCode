#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool containsDuplicate(vector<int>& nums){
	sort(nums.begin(),nums.end());
	int len = nums.size();
	for(int l = 0, r = l+1; r < len; ++l,++r){
		if(nums[l] == nums[r])
			return true;
	}
	return false;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	bool res = containsDuplicate(nums);
	cout << res << endl;
	system("pause");
	return 0;
}