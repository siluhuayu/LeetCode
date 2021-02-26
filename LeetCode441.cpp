#include<iostream>
using namespace std;
int arrangeCoins(int n){
	int i = 1,sum = 0,count = 0;
	while(sum <= n){
		if(sum <= n - i){//不用sum+i <= n: sum + i可能会越界
			sum += i;
			count++;
			i++;
		}
		else
			break;
	}
	return count;
}
int main(){
	int n;
	cin >> n;
	int count = arrangeCoins(n);
	cout << count << endl;
	system("pause");
	return 0;
}