#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> res;
string s;
string match[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void dfs(string digits,int pos){
	if(pos == digits.length()){
		res.push_back(s);
		return;
	}
	int num = digits[pos] - '0';
	for(int i = 0;i < match[num].size(); i++){
		s.push_back(match[num][i]);
        dfs(digits, pos + 1);
        s.pop_back();
    }
}
vector<string> letterCombinations(string digits){
	int len = digits.length();
	if(len == 0)
		return res;
	int i = 0;
	for(i; i < len; i++)
		if(digits[i] == '1' || digits[i] == '0')
			return res;
	dfs(digits,0);
	return res;
}
int main(){
	string digits;
	cin >> digits;
	letterCombinations(digits);
	int len = res.size();
	for(int i = 0; i < len; i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
