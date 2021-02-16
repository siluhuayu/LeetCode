#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arrayPairSum(vector<int>& nums){
	sort(nums.begin(),nums.end());
	int sum = 0;
	int n = nums.size();
	for(int i = 0; i < n; i += 2)
		sum += nums[i];
	return sum;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int sum = arrayPairSum(nums);
	cout << sum << endl;
	system("pause");
	return 0;
}