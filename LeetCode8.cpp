#include<iostream>
#include<string>
using namespace std;
int myAtoi(string s){
	int i = 0,st,base = 1,res = 0,th;
	bool flag = true;
	while(s[i] == ' ')//寻找第一个不是空白符的字符
		i++;
	if(isdigit(s[i]) || s[i] == '-' || s[i] == '+')
	{
		if(isdigit(s[i])){
			th = INT_MAX;
			while(s[i] == '0')//0000000123 输出123
				i++;
			if(!isdigit(s[i]))//00000-42a1234 输出0
				return 0;
			st = i;
			while(isdigit(s[++i])){
				if(i-st+1 > 10)
					return INT_MAX;
				base *= 10;
			}

			while(st != i){
				if(s[st]-48 > th/base){//2147483648,2147483646
					flag = true;
					return INT_MAX;
				}
				if(s[st]-48 == th/base)
					flag = false;
				th = flag ? th : th-th/base * base;	
				res += (s[st]-48) * base;
				base /= 10;
				st++;
			}
		}
		else if(s[i] == '-'){
			th = INT_MIN;
			i++;
			while(s[i] == '0')
				i++;
			i--;
			if(isdigit(s[++i])){
				st = i;
				while(isdigit(s[++i])){
					if(i-st+1 > 10)
				        return INT_MIN;//处理overflow
					base *= 10;
				}
				while(st != i){
					if(-(s[st]-48) < th/base){//逐位处理，例：-2147483649
						flag = true;
						return INT_MIN;
					}
					if(-(s[st]-48) == th/base)
						flag = false;
					th = flag ? th : th-th/base * base;	
					res -= (s[st]-48) * base;
					base /= 10;
					st++;
				}
				
			}
			else
				return 0;
		}
		else{
			th = INT_MAX;
			i++;
			while(s[i] == '0')
				i++;
			i--;
			if(isdigit(s[++i])){
				st = i;
				while(isdigit(s[++i])){
					if(i-st+1 > 10)
						return INT_MAX;
					base *= 10;
				}
				while(st != i){
					if((s[st]-48) > th/base){
						flag = true;
						return INT_MAX;
					}
					if((s[st]-48) == th/base)
						flag = false;
					th = flag ? th : th-th/base * base;	
					res += (s[st]-48) * base;
					base /= 10;
					st++;
				}
			}
			else
				return 0;
		}
	}
	else
		return 0;
	return res;
}
int main(){
	string s;
	cin >> s;
	int res = myAtoi(s);
	cout << res << endl;
	system("pause");
	return 0;
}