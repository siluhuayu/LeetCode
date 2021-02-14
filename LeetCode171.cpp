#include<iostream>
#include<string>
using namespace std;
int titleToNumber(string s){
	int n = s.length();
	int index = 0,base = 1;
	for(int i = n - 1; i >= 0; --i){
		index += (s[i] - 'A' + 1)* base;
		if(i == 0)
			break;
		else
			base *= 26;
	}
	return index;
}
int main(){
	string s;
	cin >> s;
	int index = titleToNumber(s);
	cout << index << endl;
	system("pause");
	return 0;
}