#include<iostream>
using namespace std;
//��ʱ
//bool canWinNim(int n){
//    if(n <= 3) 
//        return true;
//    if(!canWinNim(n - 1) || !canWinNim(n - 2) || !canWinNim(n - 3)) 
//        return true;
//    return false;
//}
//�����ۣ�������ѧ˼·���⣬����ο��Ľ��
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