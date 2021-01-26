#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int removeDuplicates(vector<int>& nums){
	nums.erase(unique(nums.begin(),nums.end()),nums.end());
	int len = nums.size();
	return len;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v)
	{
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int len = removeDuplicates(nums);
	cout << len << endl;
	system("pause");
	return 0;
}