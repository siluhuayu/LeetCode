#include<iostream>
#include<string>
using namespace std;
string convertToTitle(int n){
	string res;
	while(n){
		n--;
		res += (n % 26 + 'A');
		n /= 26;
	}
	reverse(res.begin(),res.end());
	return res;
}
int main(){
	int n;
	cin >> n;
	string res = convertToTitle(n);
	cout << res << endl;
	system("pause");
	return 0;
}