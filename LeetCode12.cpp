#include<iostream>
#include<string>
using namespace std;
string intToRoman(int num){
	string res;
	if(num >= 1000)
	{
		res += string(num/1000,'M');
		num = num % 1000;
	}
	if(num >= 500){
		if(num >= 900)
		{
			res = res + 'C' + 'M';
			num -= 900;
		}
		else{
			res += 'D';
			num -= 500;
		}
	}
	if(num >= 400)
	{
		res = res + 'C' + 'D';
		num -= 400;
	}
	if(num >= 100){
		res += string(num/100,'C');
		num = num % 100;
	}
	if(num >= 50){
		if(num >= 90)
		{
			res = res + 'X' + 'C';
			num -= 90;
		}
		else{
			res += 'L';
			num -= 50;
		}
	}
	if(num >= 40)
	{
		res = res + 'X' + 'L';
		num -= 40;
	}
	if(num >= 10){
		res += string(num/10,'X');
		num = num % 10;
	}
	if(num >= 5){
		if(num >= 9)
		{
			res = res + 'I' + 'X';
			num -= 9;
		}
		else{
			res += 'V';
			num -= 5;
		}
	}
	if(num >= 4)
	{
		res = res + 'I' + 'V';
		num -= 4;
	}
	if(num >= 1)
		res += string(num,'I');
	return res;
}
int main(){
	int num;
	cin >> num;
	string res = intToRoman(num);
	cout << res << endl;
	system("pause");
	return 0;
}