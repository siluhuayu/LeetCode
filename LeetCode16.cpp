#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int threeSumClosest(vector<int>& nums, int target){
	int n = nums.size();
	sort(nums.begin(),nums.end());
	int res = 100000,closestres = 100000;//因为本题中3 <= nums.length <= 10^3，-10^3 <= nums[i] <= 10^3，-10^4 <= target <= 10^4
	for(int i = 0; i < n; i++){//先固定一个元素
		if(i > 0 && nums[i] == nums[i-1])
			    continue;
        int left = i + 1, right = n - 1;
        while(left < right){
            if(nums[i] + nums[left] + nums[right] == target)
                return target;
			else if(nums[i] + nums[left] + nums[right] > target){
				res = abs(nums[i] + nums[left] + nums[right] - target);
				if(res <= abs(closestres-target))
					closestres = nums[i] + nums[left] + nums[right];
                while(nums[right - 1] == nums[right] && right >= 4)
                    right--;
                right--;
			}
			else{
				res = abs(nums[i] + nums[left] + nums[right] - target);
				if(res <= abs(closestres-target))
					closestres = nums[i] + nums[left] + nums[right];
                while(nums[left + 1] == nums[left] && left <= n - 4)
                    left++;
                left++;
            }    
        }
    }
	return closestres;
}
int main(){
	vector<int> nums;
	int v;
	while(cin >> v){
		nums.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int target;
	cin >> target;
	int closestres = threeSumClosest(nums,target);
	cout << closestres << endl;
	system("pause");
	return 0;
}
