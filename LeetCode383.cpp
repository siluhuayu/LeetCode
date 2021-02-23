#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool canConstruct(string ransomNote, string magazine){
	int n = ransomNote.length(),m = magazine.length();
	vector<int> count(26);
	for(int i = 0; i < m; ++i)
		count[magazine[i]-'a']++;
	for(int i = 0; i < n; ++i)
	{
		count[ransomNote[i]-'a']--;
		if(count[ransomNote[i]-'a'] < 0)
			return false;
	}
	return true;
}
int main(){
	string ransomNote,magazine;
	cin >> ransomNote >> magazine;
	bool res = canConstruct(ransomNote,magazine);
	cout << res << endl;
	system("pause");
	return 0;
}