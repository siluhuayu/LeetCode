#include<iostream>
#include<string>
using namespace std;
int romanToInt(string s){
	int len = s.length();
	int res = 0;
	for(int i = len - 1; i >= 0; i--){
		if(s[i] == 'I')
			res += 1;
		else if(s[i] == 'V'){
			if(i >= 1 && s[i-1] == 'I'){
				res += 4;
				i--;
			}
			else
				res += 5;
		}
		else if(s[i] == 'X')
		{
			if(i >= 1 && s[i-1] == 'I'){
				res += 9;
				i--;
			}
			else
				res += 10;
		}
		else if(s[i] == 'L'){
			if(i >= 1 && s[i-1] == 'X'){
				res += 40;
				i--;
			}
			else
				res += 50;
		}
		else if(s[i] == 'C'){
			if(i >= 1 && s[i-1] == 'X'){
				res += 90;
				i--;
			}
			else
				res += 100;
		}
		else if(s[i] == 'D'){
			if(i >= 1 && s[i-1] == 'C'){
				res += 400;
				i--;
			}
			else
				res += 500;
		}
		else{
			if(i >= 1 && s[i-1] == 'C'){
				res += 900;
				i--;
			}
			else
				res += 1000;
		}
	}
	return res;
}
int main(){
	string s;
	cin >> s;
	int res = romanToInt(s);
	cout << res << endl;
	system("pause");
	return 0;
}