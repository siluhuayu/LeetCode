#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool checkInclusion(string s1, string s2){
	vector<int> num1(26),num2(26);
	int len1 = s1.length(),len2 = s2.length();
	if(len1 > len2)
		return false;
	for(int i = 0; i < len1; ++i){
		num1[s1[i]-'a']++;
		num2[s2[i]-'a']++;
	}
	if(num1 == num2)
		return true;
	for(int i = len1; i < len2; ++i){
		num2[s2[i]-'a']++;
		num2[s2[i-len1]-'a']--;
		if(num1 == num2)
			return true;
	}
	return false;
}
int main(){
	string s1,s2;
	cin >> s1 >> s2;
	bool flag = checkInclusion(s1,s2);
	cout << flag << endl;
	system("pause");
	return 0;
}