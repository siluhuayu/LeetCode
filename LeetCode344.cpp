#include<iostream>
#include<vector>
using namespace std;
void reverseString(vector<char>& s){
	int len = s.size();
	for(int l = 0,r = len - 1; l < r; l++,r--)
		swap(s[l],s[r]);
}
int main(){
	vector<char> s;
	char v;
	while(cin >> v){
		s.push_back(v);
		if(cin.get() == '\n')
			break;
	}
	reverseString(s);
	for(int i = 0; i < s.size(); i++)
		cout << s[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}