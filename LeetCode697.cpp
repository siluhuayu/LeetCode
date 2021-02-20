#include<iostream>
#include<vector>
#include<map>
using namespace std;
int findShortestSubArray(vector<int>& nums){
	map<int,int> left,right,counter;//left记录第一次出现的位置，right记录最后一次出现的位置，counter记录出现的次数
	int degree = 0;
	int n = nums.size();
	for(int i = 0; i < n; ++i)
	{
		if(left.count(nums[i]) == 0)//count返回值只会为0/1，相当于find
			left[nums[i]] = i;
		right[nums[i]] = i;
		counter[nums[i]]++;
		degree = max(degree,counter[nums[i]]);//计算度数
	}
	int length = n;
	int m = counter.size();
	for(map<int,int>::iterator i = counter.begin(); i != counter.end(); ++i)
		if ((*i).second == degree)
			length = min(length, right[(*i).first] - left[(*i).first] + 1);
	return length;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int length = findShortestSubArray(nums);
	cout << length << endl;
	system("pause");
	return 0;
}

