#include<iostream>
#include<string>
using namespace std;
string addBinary(string a, string b){
	int lena = a.size(),lenb = b.size();
	int res[100000] = {0};
	string mul_res;
	int min_len = min(lena,lenb);
	for(int i = 0; i < min_len; ++i)
		res[i] = a[lena-1-i] - 48 + b[lenb-1-i] - 48;
	if(min_len < lena){
		for(int i = min_len; i < lena; ++i){
			res[i] = a[lena-1-i] - 48;
		}
	}
	else if(min_len < lenb){
		for(int i = min_len; i < lenb; ++i){
			res[i] = b[lenb-1-i] - 48;
		}
	}
	int len = max(lena,lenb);
	for(int k = 0; k < len; k++)
	{
		if(res[k] > 1){
			int temp = res[k];
			res[k] = temp % 2;
			res[k+1] += temp / 2;
		}
	}
	int st = (res[len] == 0 ? len-1:len);
	for(st; st >= 0; --st)
		mul_res = mul_res + to_string(res[st]);
	return mul_res;
}
int main(){
	string a,b;
	cin >> a >> b;
	string res = addBinary(a,b);
	cout << res << endl;
	system("pause");
	return 0;
}
