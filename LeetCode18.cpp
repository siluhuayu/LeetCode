#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target){
	int n = nums.size();
	vector<vector<int>> res;
	if(n < 4)
		return res;  
    sort(nums.begin(),nums.end());//排序
    for(int i = 0; i < n - 3; i++){//先固定一个元素
		if(i > 0 && nums[i] == nums[i-1])//防止重复
			continue;
		if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
			break;
		if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target)
			continue;
		for(int j = i + 1; j < n - 2; j++){//固定第二个元素
			if(j > i + 1 && nums[j] == nums[j-1])
				continue;
			if(nums[j] + nums[j+1] + nums[j+2] + nums[i] > target)
				break;
			if(nums[i] + nums[n-1] + nums[n-2] + nums[j] < target)
				continue;
            int left = j + 1, right = n - 1;
            while(left < right){//双指针法缩小范围
                if(nums[i] + nums[j] + nums[left] + nums[right] == target){//符合要求
                    vector<int> ans;
                    ans.push_back(nums[i]);
					ans.push_back(nums[j]);
                    ans.push_back(nums[left]);
                    ans.push_back(nums[right]);
                    res.push_back(ans);
                    while(nums[left + 1] == nums[left] && left <= n - 3)
                        left++;
                    left++;
                    while(nums[right - 1] == nums[right] && right >= 5)
                        right--;
                    right--;
                }
                else if(nums[i] + nums[j] + nums[left] + nums[right] > target)
                {
                    while(nums[right - 1] == nums[right] && right >= 5)
                        right--;
                    right--;
                }
                else{
                    while(nums[left + 1] == nums[left] && left <= n - 3)
                        left++;
                    left++;
                }
            }
        }
	}
    return res;
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
	int target;
	cin >> target;
	vector<vector<int>> res = fourSum(nums,target);
	int len = res.size();
	for(int i = 0; i < len; i++){
		for(int j = 0; j < 4; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}