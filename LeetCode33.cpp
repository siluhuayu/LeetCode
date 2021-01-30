#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target){
	int len = nums.size();
	for(int i = 0; i < len; i++)
	{
		if(nums[i] == target)
			return i;
	}
	return -1;
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
	int res = search(nums,target);
	cout << res << endl;
	system("pause");
	return 0;
}