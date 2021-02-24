#include<iostream>
#include<string>
using namespace std;
string toHex(int num){
	string hex[16] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
	string res;
	long long n = num;
	if(n == 0)
		return "0";
	if(n < 0)
		n += 0x100000000;
	while(n){
		res = hex[n%16] + res;
		n /= 16;
	}
	return res;
}
int main(){
	int num;
	cin >> num;
	string res = toHex(num);
	cout << res << endl;
	system("pause");
	return 0;
}
