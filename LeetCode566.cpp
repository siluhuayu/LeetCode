#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c){
	int m = nums.size();
	int n = nums[0].size();//二维数组行，列统计方法
	if( m * n != r * c)
		return nums;
	vector<vector<int>> res(r,vector<int>(c));
	int x = 0, y = 0;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j){
			res[i][j] = nums[x][y];
			y++;
			if(y == n)
			{
				x++;
				y = 0;
			}
		}
	return res;
}
int main(){
	vector<vector<int>> nums;
	vector<int> input;
	string temp;
	while((getline(cin, temp)) && temp != "")//二维数组输入的方法，但要注意最后一行输入结束要再按一个回车
	{
		for(int i = 0; i < temp.size(); ++i) 
		{
			int num = 0;
			while (temp[i] != ' ' && temp[i] != '\0')
			{
				num = num * 10 + (temp[i] - '0');
				++i;
			}
			input.push_back(num);
		}
		nums.push_back(input);
		input.clear();
	}
	int r,c;
	cin >> r >> c;
	vector<vector<int>> res = matrixReshape(nums,r,c);
	int m = res.size();
	int n = res[0].size();//用m,n而不是r,c，防止重塑失败后返回nums
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}