#include<iostream>
#include<vector>
using namespace std;
vector<int> plusOne(vector<int>& digits){
	int len = digits.size();
	int i;
	for(i = len - 1; i >= 0; --i)
	{
		if(digits[i] <= 8)
		{
			digits[i]++;
			break;	
		}
	}
	for(int j = i+1;j < len;++j)
		digits[j] = 0;	
	if(i == -1)
		digits.insert(digits.begin(),1);
	return digits;
}
int main(){
	vector<int> digits;
	int v;
	while(cin >> v){
		digits.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	vector<int> res = plusOne(digits);
	int n = res.size();
	for(int i = 0; i < n; ++i)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}