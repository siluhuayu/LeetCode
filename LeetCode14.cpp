#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longestCommonPrefix(vector<string>& strs){
	string longesthead;
	int n = strs.size();
	if(n == 0)//Îð¶ª
		return longesthead;
	int len = strs[0].size();
	bool flag = true;
	for(int ans = 0; ans < len; ans++){
		for(int i = 0; i < n; i++){
			if(strs[i][ans] == strs[0][ans])
				continue;
			else{
				flag = false;
				break;
			}
		}
		if(flag)
			longesthead += strs[0][ans];
		else
			break;
	}
	return longesthead;
}
int main(){
	vector<string> strs;
	string v;
	while(cin >> v)
	{
		strs.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	string longesthead = longestCommonPrefix(strs);
	cout << longesthead << endl;
	system("pause");
	return 0;
}