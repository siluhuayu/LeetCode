#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char findTheDifference(string s, string t){
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	int n = s.length();
	for(int i = 0; i < n; ++i)
		if(s[i] != t[i])
			return t[i];
	return t[n];
}
int main(){
	string s,t;
	cin >> s >> t;
	char dif = findTheDifference(s,t);
	cout << dif << endl;
	system("pause");
	return 0;
}