#include<iostream>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target){
	vector<int> ans;
	int left = 0,right = numbers.size() - 1;
	while(left < right){
		if(numbers[left] + numbers[right] == target){
			ans.push_back(left+1);
			ans.push_back(right+1);
			break;
		}
		else if(numbers[left] + numbers[right] > target)
			right--;
		else
			left++;
	}
	return ans;
}
int main(){
	vector<int> numbers;
	int v;
	while(cin >> v){
		numbers.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	int target;
	cin >> target;
	vector<int> ans = twoSum(numbers,target);
	for(int i = 0; i < 2; ++i)
		cout << ans[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}