#include<iostream>
using namespace std;
bool isPalindrome(int x){
	int base = 1,th = INT_MAX;
	int temp = x;
	bool flag = true;
	if(x < 0)
		return false;
	while (temp >= 10){
		base *= 10;
		temp /= 10;
	}
	temp = x;
	int pal = 0;
	while(temp >= 10){
		if((temp % 10) > th/base){
			flag = true;
			return false;
		}
		flag = true;
		if((temp % 10) == th/base)
			flag = false;
		th = flag ? th:(th - th/base * base);
		pal += temp%10 * base;
		base /= 10;
		temp /= 10;
	}
	if(flag || temp <= 7)
		pal += temp;
	else
		return false;
	return pal == x ? true : false;
}
int main(){
	int x;
	cin >> x;
	bool flag = isPalindrome(x);
	cout << flag << endl;
	system("pause");
	return 0;
}