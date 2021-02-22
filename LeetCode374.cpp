#include<iostream>
using namespace std;
int pick;
//该guess函数按照测试代码写的，但与文字描述似乎反了
int guess(int num){
	if(num > pick)
		return -1;
	else if(num < pick)
		return 1;
	else
		return 0;
}
int guessNumber(int n){
	int l = 1, r = n;
	int mid;
	while(l < r){
		mid = l + (r - l)/2;//不直接写(r+l)/2,因为会整数越界
		if(guess(mid) == 0)
			return mid;
		else if(guess(mid) > 0)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}
int main(){
	int n;
	cin >> n >> pick;
	int res = guessNumber(n);
	cout << res << endl;
	system("pause");
	return 0;
}