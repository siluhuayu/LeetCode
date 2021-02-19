#include<iostream>
using namespace std;
//超时
//bool canWinNim(int n){
//    if(n <= 3) 
//        return true;
//    if(!canWinNim(n - 1) || !canWinNim(n - 2) || !canWinNim(n - 3)) 
//        return true;
//    return false;
//}
//博弈论，根据数学思路来解，代码参考的解答
bool canWinNim(int n){
	return n%4;
}
int main(){
	int n;
	cin >> n;
	bool res = canWinNim(n);
	cout << res << endl;
	system("pause");
	return 0;
}