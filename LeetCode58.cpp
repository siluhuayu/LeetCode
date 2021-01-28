#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s){
	int len = s.length();
	int count = 0;
	bool flag = false;
	for(int i = len - 1; i >= 0; i--)
	{
		if(isalpha(s[i])){
			flag = true;
			count++;
		}
		if(isspace(s[i]) && flag)
			break;
	}
	return count;
}
int main(){
	string s;
	cin >> s;
	int len = lengthOfLastWord(s);
	cout << len << endl;
	system("pause");
	return 0;
}