#include<iostream>
#include<vector>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k){
	int len = nums.size();
    int l = -1, r = 0;
    while (r < len){
		if (l + 1 < len && l + 1 <= r + k)
			l++;
		else
			r++;
		if(l <= r)
			continue;
		if(nums[l] == nums[r])
			return true;
    }
    return false;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int k;
	cin >> k;
	bool res = containsNearbyDuplicate(nums,k);
	cout << res << endl;
	system("pause");
	return 0;
}