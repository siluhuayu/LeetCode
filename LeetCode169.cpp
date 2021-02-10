#include<iostream>
#include<vector>
#include<map>
using namespace std;
int majorityElement(vector<int>& nums){
	map<int,int> count;
	int len = nums.size();
	int i;
	for(i = 0; i < len; ++i){
		count[nums[i]]++;
		if(count[nums[i]] > len/2)
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
	int res = majorityElement(nums);
	cout << res << endl;
	system("pause");
	return 0;
}