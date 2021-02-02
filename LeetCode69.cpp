#include<iostream>
using namespace std;
int mySqrt(int x){
	int i;
	if(x == 0)
		return 0;
	for(i = 1; i < x ;++i){
		if( i > x/i)
			break;
	}
	return i == 1 ? 1:i-1;
}
int main(){
	int x;
	cin >> x;
	int i = mySqrt(x);
	cout << i << endl;
	system("pause");
	return 0;
}