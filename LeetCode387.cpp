#include<iostream>
#include<string>
#include<map>
using namespace std;
int firstUniqChar(string s){
	map<char,int> count;
	int n = s.length();
	for(int i = 0; i < n; ++i)
		count[s[i]]++;
	for(int i = 0; i < n; ++i)
		if(count[s[i]] == 1)
			return i;
	return -1;
}
int main(){
	string s;
	cin >> s;
	int ans = firstUniqChar(s);
	cout << ans << endl;
	system("pause");
	return 0;
}