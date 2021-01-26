#include<iostream>
#include<string>
using namespace std;
int lengthOfLongestSubstring(string s){
	int len = 1,maxlen = 1,k;
	if(s.length() == 0)//处理空字符串
		return 0;
	for(int i = 0; i < s.size(); i++){
		for(int j = i + 1; j < s.size(); j++){
			for(k = i; k < j; k++){//确保与之前所有字符均不重复，注意判断首字符不一定是整个字符串首字符，k从i开始，而不是0
				if(s[k] == s[j])
					break;
			}
			if(k == j)
				len++;
			else 
				break;
		}
		if(len >= maxlen)//判断最大长度
			maxlen = len;
		len = 1;
	}
	return maxlen;
}
int main(){
	string s;
	cin >> s;
	//s = "";
	int maxlen = lengthOfLongestSubstring(s);
	cout << maxlen;
	system("pause");
	return 0;
}
