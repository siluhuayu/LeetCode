#include<iostream>
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums){
	int count = 0,maxcount = 0;
	int len = nums.size();
	for(int i = 0; i < len; ++i)
	{
		if(nums[i])
			count++;
		else
			count = 0;
		if(count > maxcount)
			maxcount = count;
	}
	return maxcount;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int maxcount = findMaxConsecutiveOnes(nums);
	cout << maxcount << endl;
	system("pause");
	return 0;
}