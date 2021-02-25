#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> transpose(vector<vector<int>>& matrix){
	int m = matrix.size(),n = matrix[0].size();
	vector<vector<int>> res(n,vector<int>(m));
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
            res[j][i] = matrix[i][j];
	return res;
}
int main(){
		vector<vector<int>> A;
	vector<int> input;
	string temp;
	while((getline(cin, temp)) && temp != "")//��ά��������ķ�������Ҫע�����һ���������Ҫ�ٰ�һ���س�
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
	vector<vector<int>> res = transpose(A);
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
