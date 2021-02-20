#include<iostream>
#include<string>
using namespace std;
bool isVowel(char a){
    if(tolower(a) == 'a' || tolower(a) == 'e' || tolower(a) == 'i' || tolower(a) == 'o' || tolower(a) == 'u')
        return true;
    return false;
}	
string reverseVowels(string s){
    int len = s.length();
    int l = 0,r = len - 1;
    while(l < r){
        while(l < len && !isVowel(s[l]))
            l++;
        while(r >=0 && !isVowel(s[r]))
            r--;
        if(l >= r)
            break;
        swap(s[l++],s[r--]);
    }
    return s;
}
int main(){
	string s;
	cin >> s;
	string res = reverseVowels(s);
	cout << res << endl;
	system("pause");
	return 0;
}