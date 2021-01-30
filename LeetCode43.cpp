#include<iostream>
#include<string>
#include<vector>
using namespace std;
string multiply(string num1, string num2){
	if(num1 == "0" || num2 == "0")
		return "0";
	int len1 = num1.size(),len2 = num2.size();
	int res[100000] = {0};
	string mul_res;
	int i,j;
	for(i = len2 - 1; i >= 0; i--){
		for(j = len1 - 1; j >= 0; j--){
			res[len1-1-i+len2-1-j] += (num1[j] - 48) * (num2[i] - 48);
		}
	}
	for(int k = 0; k < len1 + len2; k++)
	{
		if(res[k] > 9){
			int temp = res[k];
			res[k] = temp % 10;
			res[k+1] += temp / 10;
		}
	}
	int st = (res[len1+len2-1] == 0 ? len1+len2-2:len1+len2-1);
	for(st; st >= 0; --st)
		mul_res = mul_res + to_string(res[st]);
	return mul_res;
}
int main(){
	string num1,num2;
	cin >> num1 >> num2;
	string res = multiply(num1,num2);
	cout << res << endl;
	system("pause");
	return 0;
}
