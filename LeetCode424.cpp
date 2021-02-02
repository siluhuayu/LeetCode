#include<iostream>
#include<string>
#include<vector>
using namespace std;
int characterReplacement(string s, int k){
	vector<int> count(26);
	int len = s.length();
	int maxlen = 0;
	int l = 0, r = 0;
	while(r < len){
		count[s[r]-'A']++;
		maxlen = max(maxlen,count[s[r]-'A']);
		if(r - l + 1 - maxlen > k){
			count[s[l]-'A']--;
			l++;
		}
		r++;
	}
	return r - l;
}
int main(){
	string s;
	cin >> s;
	int k;
	cin >> k;
	int maxlen = characterReplacement(s,k);
	cout << maxlen << endl;
	system("pause");
	return 0;
}