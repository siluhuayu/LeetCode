#include<iostream>
#include<vector>
#include<string>
using namespace std;
int thirdMax(vector<int>& nums){
	int n = nums.size();
	if(n == 1)
		return nums[0];
	if(n == 2)
		return max(nums[0],nums[1]);
	long firstmax = (long) INT_MIN - 1,secondmax = (long) INT_MIN - 1,thirdmax = (long) INT_MIN - 1;
	for(int i = 0; i < n; ++i){
		if(nums[i] > firstmax){
			thirdmax = secondmax;
			secondmax = firstmax;
			firstmax = nums[i];
		}
		else if(nums[i] < firstmax && nums[i] > secondmax){
			thirdmax = secondmax;
			secondmax = nums[i];
		}
		else if(nums[i] < secondmax && nums[i] > thirdmax){
			thirdmax = nums[i];
		}
	}
	return thirdmax == (long) INT_MIN - 1? (int)firstmax:(int)thirdmax;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int res = thirdMax(nums);
	cout << res << endl;//在LeetCode上测试输出结果正确，可能编译器不同？
	system("pause");
	return 0;
}