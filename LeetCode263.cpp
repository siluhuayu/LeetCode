#include<iostream>
using namespace std;
bool isUgly(int num){
	if(num == 1)
		return false;
	while(num != 0){
		if(num == 1)
			return true;
		if(num % 2 == 0)
			num /= 2;
		else if(num % 3 == 0)
			num /= 3;
		else if(num % 5 == 0)
			num /= 5;
		else
			return false;
	}
	return true;
}
int main(){
	int num;
	cin >> num;
	bool res = isUgly(num);
	cout << res << endl;
	system("pause");
	return 0;
}