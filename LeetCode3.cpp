#include<iostream>
#include<string>
using namespace std;
int lengthOfLongestSubstring(string s){
	int len = 1,maxlen = 1,k;
	if(s.length() == 0)//������ַ���
		return 0;
	for(int i = 0; i < s.size(); i++){
		for(int j = i + 1; j < s.size(); j++){
			for(k = i; k < j; k++){//ȷ����֮ǰ�����ַ������ظ���ע���ж����ַ���һ���������ַ������ַ���k��i��ʼ��������0
				if(s[k] == s[j])
					break;
			}
			if(k == j)
				len++;
			else 
				break;
		}
		if(len >= maxlen)//�ж���󳤶�
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
