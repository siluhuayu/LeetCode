#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A){
	int n = A.size();
	int m = A[0].size();
	for(int i = 0;i < n; ++i){
		reverse(A[i].begin(),A[i].end());
		for(int j = 0; j < m; ++j)
		{
			if(A[i][j] == 1)
				A[i][j] = 0;
			else
				A[i][j] = 1;
		}
	}
	return A;
}
int main(){
	vector<vector<int>> A;
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
		A.push_back(input);
		input.clear();
	}
	vector<vector<int>> res = flipAndInvertImage(A);
	int m = res.size();
	int n = res[0].size();
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}