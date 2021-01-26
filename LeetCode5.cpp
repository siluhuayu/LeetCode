#include<iostream>
#include<string>
using namespace std;
string longestPalindrome(string s){
	string palindrome;
	int st,ed,len = 0,maxlen = 0;
	int length = s.length();
	for(int i = 0; i < length; i++)
		for(int j = length - 1; j >= 0; j--){
			int k = i,m = j;
			len = 0;
			if(s[k] == s[m]){
				st = k;
				ed = m;
				while(k < m){
					if(s[k] != s[m])
						break;
					k++;
					m--;
				}
				if(k == m || (k == m+1 && s[k] == s[m]))
					len = ed - st + 1;
				if(len > maxlen){
					maxlen = len;
					palindrome = s.substr(st,maxlen);
					break;
				}
			}
		}
	return palindrome;
}
int main(){
	string s;
	cin >> s;
	string palindrome = longestPalindrome(s);
	cout << palindrome << endl;
	system("pause");
	return 0;
}