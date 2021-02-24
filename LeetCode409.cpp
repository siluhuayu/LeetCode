#include<iostream>
#include<string>
using namespace std;
int longestPalindrome(string s){
	int count[52] = {0};
	int n = s.length();
	for(int i = 0; i < n; ++i)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
			count[s[i]-'a']++;
		else
			count[s[i]-'A'+26]++;
	}
	int len = 0;
	bool flag = false;
	for(int i = 0; i < 52; ++i)
	{
		if(count[i]%2 == 0 && len%2 == 0)
			len += count[i];
		else{
			len += count[i]/2 * 2;
			flag = true;
		}
	}
	return flag?len+1:len;
}
int main(){
	string s;
	cin >> s;
	int len = longestPalindrome(s);
	cout << len << endl;
	system("pause");
	return 0;
}

