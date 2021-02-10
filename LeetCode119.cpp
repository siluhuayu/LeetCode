#include<iostream>
#include<vector>
using namespace std;
vector<int> getRow(int rowIndex){
	vector<vector<int>> res(rowIndex + 1);
	for(int i = 0;i <= rowIndex;++i){
		res[i].resize(i+1);
		res[i][0] = 1;
		res[i][i] = 1;
		for(int j = 1; j < i; ++j)
			res[i][j] = res[i-1][j-1] + res[i-1][j];
	}
	return res[rowIndex];
}
int main(){
	int rowIndex;
	cin >> rowIndex;
	vector<int> res = getRow(rowIndex);
	for(int i = 0; i <= rowIndex; ++i)
		cout << res[i] << " ";	
	cout << endl;
	system("pause");
	return 0;
}