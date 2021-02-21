#include<iostream>
#include<vector>
#include<map>
using namespace std;
int longestSubarray(vector<int>& nums, int limit){
	map<int,int> cnt;
    int length = 1, n = nums.size();
    for(int left = 0, right = 0; right < n; right++){//符合要求就右移
        cnt[nums[right]]++;//统计个数
        while(cnt.rbegin()->first - cnt.begin()->first > limit)//右-左>limit
			if(--cnt[nums[left++]] == 0)//如果最左侧元素只有一个
				cnt.erase(nums[left-1]);//删除该元素
        length = max(length, right - left + 1);
    }
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
	int limit;
	cin >> limit;
	int length = longestSubarray(nums,limit);
	cout << length << endl;
	system("pause");
	return 0;
}