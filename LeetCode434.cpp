#include<iostream>
#include<string>
using namespace std;
int countSegments(string s){
	int count = 0;
	int n = s.length();
	bool flag = false;
	for(int i = 0; i < n; ){
		while(i < n && isspace(s[i]))
			++i;
		while(i < n && !isspace(s[i])){
			++i;
			flag = true;
		}
		if(flag)
		{
			count++;
			flag = false;
		}
	}
	return count;
}
int main(){
	string s;
	getline(cin,s);//带空格的整行读入方式
	int count = countSegments(s);
	cout << count << endl;
	system("pause");
	return 0;
}