#include<iostream>
#include<vector>
using namespace std;
int pivotIndex(vector<int>& nums){
	int len = nums.size();
	int sum = 0,leftsum = 0,rightsum = 0;
	for(int i = 0; i < len; i++)
		sum += nums[i];
	for(int i = 0; i < len; i++){
		rightsum = sum - leftsum - nums[i];
		if(rightsum == leftsum)
			return i;
		else
			leftsum += nums[i];
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
	int res = pivotIndex(nums);
	cout << res << endl;
	system("pause");
	return 0;
}