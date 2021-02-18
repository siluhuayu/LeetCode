#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isAnagram(string s, string t){
	int ls = s.length(),lt = t.length();
	if(ls != lt)
		return false;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	if(s == t)
		return true;
	else
		return false;
}
int main(){
	string s,t;
	cin >> s >> t;
	bool res = isAnagram(s,t);
	cout << res << endl;
	system("pause");
	return 0;
}