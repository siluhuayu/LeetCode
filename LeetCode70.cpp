#include<iostream>
using namespace std;
int climbStairs(int n){
	int a = 0,b = 0,c = 1;
	for(int i = 1; i <= n; ++i){	
		a = b;
		b = c;
		c = a + b;
	}
	return c;
}
int main(){
	int n;
	cin >> n;
	int solutions = climbStairs(n);
	cout << solutions << endl;
	system("pause");
	return 0;
}