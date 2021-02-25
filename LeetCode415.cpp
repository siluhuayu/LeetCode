#include<iostream>
#include<string>
using namespace std;
string addStrings(string num1, string num2){
	int len1 = num1.length(),len2 = num2.length();
	int add = 0,sum = 0;
	string res;
	int i = len1-1,j = len2-1;
	for(; i >= 0 && j >= 0; i--,j--){
		sum = num1[i] - '0' + num2[j] - '0' + add;
		add = 0;
		if(sum >= 10)
		{
			add = 1;
			sum -= 10;
		}
		res = to_string(sum) + res;
	}
	if(j >= 0)
	{
		while(j >= 0)
		{
			sum = num2[j] -'0' + add;
			add = 0;
			if(sum >= 10)
			{
				add = 1;
				sum -= 10;
			}
			res = to_string(sum) + res;
			j--;
		}
	}
	if(i >= 0)
	{
		while(i >= 0)
		{
			sum = num1[i] -'0' + add;
			add = 0;
			if(sum >= 10)
			{
				add = 1;
				sum -= 10;
			}
			res = to_string(sum) + res;
			i--;
		}
	}
	return add ? to_string(add) + res : res;
}
int main(){
	string num1,num2;
	cin >> num1 >> num2;
	string res = addStrings(num1,num2);
	cout << res << endl;
	system("pause");
	return 0;
}