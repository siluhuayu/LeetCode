#include<iostream>
using namespace std;
int arrangeCoins(int n){
	int i = 1,sum = 0,count = 0;
	while(sum <= n){
		if(sum <= n - i){//����sum+i <= n: sum + i���ܻ�Խ��
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