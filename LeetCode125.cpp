#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string s){
	int i = 0, j = s.length();
	while(i < j){
		if(tolower(s[i]) == tolower(s[j]))
		{
			i++;
			j--;
		}
		else if(!isalpha(s[j]) && !isdigit(s[j]))
			j--;
		else if(!isalpha(s[i]) && !isdigit(s[i]))
			i++;
		else
			return false;
	}
	return true;
}
int main(){
	string s;
	cin >> s;
	bool res = isPalindrome(s);
	cout << res << endl;
	system("pause");
	return 0;
}