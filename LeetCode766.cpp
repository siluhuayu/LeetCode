#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isToeplitzMatrix(vector<vector<int>>& matrix){
	int m = matrix.size();
	int n = matrix[0].size();
	for(int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] != matrix[i - 1][j - 1])
                return false;
    return true;
}
int main(){
	vector<vector<int>> matrix;
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
		matrix.push_back(input);
		input.clear();
	}
	bool res = isToeplitzMatrix(matrix);
	cout << res << endl;
	system("pause");
	return 0;
}