#include<iostream>
#include<vector>
#include<map>
using namespace std;
int longestSubarray(vector<int>& nums, int limit){
	map<int,int> cnt;
    int length = 1, n = nums.size();
    for(int left = 0, right = 0; right < n; right++){//����Ҫ�������
        cnt[nums[right]]++;//ͳ�Ƹ���
        while(cnt.rbegin()->first - cnt.begin()->first > limit)//��-��>limit
			if(--cnt[nums[left++]] == 0)//��������Ԫ��ֻ��һ��
				cnt.erase(nums[left-1]);//ɾ����Ԫ��
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