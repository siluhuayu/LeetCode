#include<iostream>
using namespace std;
//bool isPerfectSquare(int num){
//	if(num == 1)
//		return true;
//	for(int i = 2; i < num/2; ++i)
//		if(i == num/i)
//			return true;
//	return false;
//}
bool isPerfectSquare(int num){
	int l = 0, r = num;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mid * mid < num) 
			l = mid + 1;
        else 
			r = mid;
    }
    return l * l == num;
}
int main(){
	int num;
	cin >> num;
	bool res = isPerfectSquare(num);
	cout << res << endl;
	system("pause");
	return 0;
}