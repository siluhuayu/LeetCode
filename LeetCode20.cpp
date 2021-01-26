#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string s){
	stack<char> st;
	int len = s.length();
	for(int i = 0; i < len; i++){
		if(s[i] == '{')
			st.push('}');
		else if(s[i] == '[')
			st.push(']');
		else if(s[i] == '(')
			st.push(')');
		else if(st.empty() || s[i] != st.top())
			return false;
		else
			st.pop();
	}
	return st.empty();
}
int main(){
	string s;
	cin >> s;
	cout << isValid(s) << endl;
	system("pause");
	return 0;
}