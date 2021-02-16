#include<iostream>
using namespace std;
//int addDigits(int num){
//	int sum = 0;
//	while(num > 9)
//	{
//		sum = 0;
//		while(num > 9){
//			sum += num % 10;
//			num /= 10;
//		}
//		sum += num;
//		num = sum;
//	}
//	return num;
//}
int addDigits(int num){
	if(num == 0)
		return 0;
	if(num % 9 == 0)
		return 9;
	return num % 9;
}
int main(){
	int num;
	cin >> num;
	int sum = addDigits(num);
	cout << sum << endl;
	system("pause");
	return 0;
}