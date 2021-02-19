#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>& nums){
	int ans = 0;
	int n = nums.size();
	for(int i = 0; i < n; ++i){
		if(nums[i])
			nums[ans++] = nums[i];
	}
	for(int i = ans; i < n; ++i)
		nums[i] = 0;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	moveZeroes(nums);
	for(int i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
