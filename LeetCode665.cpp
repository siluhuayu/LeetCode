#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool checkPossibility(vector<int>& nums){
	int len = nums.size();
	for(int i = 0; i < len - 1; ++i){
		int a = nums[i],b = nums[i+1];
		if(a > b)
		{
			nums[i] = b;
			if(is_sorted(nums.begin(),nums.end()))
				return true;
			nums[i] = a;
			nums[i+1] = a;
			return is_sorted(nums.begin(),nums.end());
		}
	}
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	bool res = checkPossibility(nums);
	cout << res << endl;
	system("pause");
	return 0;
}