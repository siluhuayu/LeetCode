#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int removeElement(vector<int>& nums, int val){
	int i = 0;
	sort(nums.begin(),nums.end());
	int len = nums.size();
	bool flag = false;
	for(i; i < len; ){
		if(flag && nums[i] != val)
			break;
		if(nums[i] == val){
			flag = true;
			nums.erase(nums.begin() + i);
			len--;
		}
		else
			i++;
	}
	return nums.size();
}
int main(){
	vector<int> nums;
	int v;
	while (cin >> v)
	{
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int val;
	cin >> val;
	int len = removeElement(nums,val);
	cout << len << endl;
	system("pause");
	return 0;
}