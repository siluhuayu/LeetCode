#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums){
	int n = nums.size();
	vector<int> res;
	sort(nums.begin(),nums.end());
	int k = 1;
	for(int i = 0; i < n; ++i){
		if(nums[i] > k){
			i--;
			res.push_back(k);
			k++;
		}
		else if(nums[i] == k){
			if(i < n - 1 && nums[i+1] != k)
				k++;
		}
	}
	k++;
	while(k <= n){
		res.push_back(k);
		k++;
	}
	return res;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	vector<int> res = findDisappearedNumbers(nums);
	for(int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}