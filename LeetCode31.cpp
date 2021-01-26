#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums){
	int len = nums.size();
	if(len <= 1)
		return;
	int m = 0,j;
	for(m = 0; m < len - 1; m++){
		for(j = m + 1; j < len; j++){
			if(nums[j] <= nums[m]);
			else
				break;
		}
		if(j != len)
			break;
	}
	if(m == len - 1)
	{
		sort(nums.begin(),nums.end());
		return;
	}
	int i = len - 1,bg = 0,ed;
	for(i; i >= 0; i--){
		for(j =  i - 1; j >= 0; j--){
			if(j > 0 && nums[j] < nums[i]){
				if(j > bg){
					bg = j;
					ed = i;
				}
			}	
		}
	}
	//4 2 0 2 3 2 0,  2 3 0 2 4 1,  5 4 7 5 3 2
	//4 2 0 3 0 2 2,  2 3 0 4 1 2,  5 5 2 3 4 7
	if(bg){
		swap(nums[bg],nums[ed]);
		sort(nums.begin()+bg+1,nums.end());	
		return;
	}
	if(i < 0 && j < 0){
			int k = 0,ans = 0;
			int minusres = 10000,minminus = 10000;
			for(k; k < len; k++)
				if(nums[k] > nums[0]){
					minusres = nums[k] - nums[0];
					if(minusres < minminus){
						ans = k;
						minminus = minusres;
					}
				}
			int temp = nums[ans];
			for(int m = ans - 1; m >= 0; m--){
				nums[m+1] = nums[m];
			}
			nums[0] = temp;
			sort(nums.begin()+1,nums.end());
		}
	//直接利用库函数：next_permutation(nums.begin(),nums.end());
		//int i = nums.size() - 2;
  //      while (i >= 0 && nums[i] >= nums[i + 1]) {
  //          i--;
  //      }
  //      if (i >= 0) {
  //          int j = nums.size() - 1;
  //          while (j >= 0 && nums[i] >= nums[j]) {
  //              j--;
  //          }
  //          swap(nums[i], nums[j]);
  //      }
  //      reverse(nums.begin() + i + 1, nums.end());
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
	nextPermutation(nums);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}