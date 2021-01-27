#include<iostream>
#include<string>
using namespace std;	
string countAndSay(int n){
	if(n == 1)
		return "1";
	string num;
	num = countAndSay(n - 1);
	int len = num.size(),count = 1;
	string res;
	for(int i = 0; i < len; )
	{
		while(num[i] == num[i+1]){
			i++;
			count++;
		}	
		res = res + to_string(count) + to_string(num[i++]-48);
		count = 1;
	}
	return res;
}
int main(){
	int n;
	cin >> n;
	string res = countAndSay(n);
	cout << res << endl;
	system("pause");
	return 0;
}